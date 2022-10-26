// cl.exe /c /EHsc Window.c
// rc.exe Window.rc
// link.exe Window.obj Window.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS

// Header Files
#include <Windows.h>
#include "Window.h"
#include "AutomationServer.h"

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
    IMyMath *pIMyMath = NULL;
    HRESULT hr;
    int num1, num2, sum, sub;
    TCHAR str[255];

    // Code
    switch (iMsg)
    {
        case WM_CREATE:
            hr = CoInitialize(NULL);
            if(FAILED(hr))
            {
                MessageBox(hwnd, TEXT("CoInitialize Failed"), TEXT("Error"), MB_OK);
                DestroyWindow(hwnd);
            }

            hr = CoCreateInstance(CLSID_MyMath, 
                                    NULL, 
                                    CLSCTX_INPROC_SERVER, 
                                    IID_IMyMath, 
                                    (void **)&pIMyMath);

            if(FAILED(hr))
            {
                MessageBox(hwnd, TEXT("CoCreateInstance Failed To Get IMyMath Interface"), TEXT("Error"), MB_OK);
                DestroyWindow(hwnd);
            }

            num1 = 175;
            num2 = 125;
            pIMyMath->SumOfTwoIntegers(num1, num2, &sum);
            wsprintf(str, TEXT("Sum of %d and %d = %d"), num1, num2, sum);
            MessageBox(hwnd, str, TEXT("Sum"), MB_OK);

            pIMyMath->SubtractionOfTwoIntegers(num1, num2, &sub);
            wsprintf(str, TEXT("Subtraction of %d and %d = %d"), num1, num2, sub);
            MessageBox(hwnd, str, TEXT("Subtract"), MB_OK);

            pIMyMath->Release();
            pIMyMath = NULL;
            DestroyWindow(hwnd);

            break;

        case WM_DESTROY:
            CoUninitialize();
            PostQuitMessage(0);
            break;
        
        default:
            break;
    }

    return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
// End of WndProc()
