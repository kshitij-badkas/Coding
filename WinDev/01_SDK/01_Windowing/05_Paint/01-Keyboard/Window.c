// cl.exe /c /EHsc Window.c
// rc.exe Window.rc
// link.exe Window.obj Window.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS

// Header Files
#include <Windows.h>

#include "Window.h"     //*

// Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable Declaration

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // Local Variable Declaration
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("WINDEV");

    // Code
    // WNDCLASSEX Initialization
    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

    // WNDCLASSEX Registration
    RegisterClassEx(&wndclass);

    // Window Creation
    hwnd = CreateWindow(szAppName, 
        TEXT("KAB : Window"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    // Show Window
    ShowWindow(hwnd, iCmdShow);

    // Update Window
    UpdateWindow(hwnd);

    // Message Loop
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return((int)msg.wParam);
}
// End of WinMain()

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Local Variable Declaration
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rc;

    HBRUSH hBrush;                 //*
    static int iPaintFlag = 0;     //*

    // Code
    switch (iMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        case WM_CHAR:
            switch (wParam)
            {
                case 'R':
                case 'r':
                    iPaintFlag = 1;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                
                case 'G':
                case 'g':
                    iPaintFlag = 2;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;

                case 'B':
                case 'b':
                    iPaintFlag = 3;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;

                case 'C':
                case 'c':
                    iPaintFlag = 4;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;

                case 'M':
                case 'm':
                    iPaintFlag = 5;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;

                case 'Y':
                case 'y':
                    iPaintFlag = 6;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;

                case 'K':
                case 'k':
                    iPaintFlag = 7;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;

                case 'W':
                case 'w':
                    iPaintFlag = 8;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                
                default:
                    iPaintFlag = 0;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
            }
            break;
        
        case WM_PAINT:
            GetClientRect(hwnd, &rc);
            if(iPaintFlag == 1)         // Red
            {
                hBrush = CreateSolidBrush(RGB(255, 0, 0));
            }
            else if(iPaintFlag == 2)    // Green
            {
                hBrush = CreateSolidBrush(RGB(0, 255, 0));
            }
            else if(iPaintFlag == 3)    // Blue
            {
                hBrush = CreateSolidBrush(RGB(0, 0, 255));
            }
            else if(iPaintFlag == 4)    // Cyan
            {
                hBrush = CreateSolidBrush(RGB(0, 255, 255));
            }
            else if(iPaintFlag == 5)    // Magenta
            {
                hBrush = CreateSolidBrush(RGB(255, 0, 255));
            }
            else if(iPaintFlag == 6)    // Yellow
            {
                hBrush = CreateSolidBrush(RGB(255, 255, 0));
            }
            else if(iPaintFlag == 7)    // Black
            {
                hBrush = CreateSolidBrush(RGB(0, 0, 0));
            }
            else if(iPaintFlag == 8)    // White
            {
                hBrush = CreateSolidBrush(RGB(255, 255, 255));
            }
            else                        // Grey
            {
                hBrush = CreateSolidBrush(RGB(128, 128, 128));
            }

            hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &rc, hBrush);
            DeleteObject(hBrush);  
            EndPaint(hwnd, &ps);
            break;
        
        default:
            break;
    }

    return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
// End of WndProc()
