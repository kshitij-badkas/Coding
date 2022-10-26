// Header Files
#include <Windows.h>

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
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

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
    TCHAR str[255];

    int num1 = 0, num2 = 0, num3 = 0;   //*

    // Code
    switch (iMsg)
    {
        case WM_CREATE:
            num1 = 25;                  //*
            num2 = 75;                  //*
            num3 = num1 + num2;         //*
    
            // wsprintf(str, TEXT("WM_CREATE Message is Received."));
            wsprintf(str, TEXT("Sum of %d & %d is %d."), num1, num2, num3);     //*
            MessageBox(hwnd, str, TEXT("Message"), MB_OK);
            break;

        case WM_KEYDOWN:
            wsprintf(str, TEXT("WM_KEYDOWN Message is Received."));
            MessageBox(hwnd, str, TEXT("Message"), MB_OK);
            break;

        case WM_LBUTTONDOWN:
            wsprintf(str, TEXT("WM_LBUTTONDOWN Message is Received."));
            MessageBox(hwnd, str, TEXT("Message"), MB_OK);
            break;

        case WM_RBUTTONDOWN:
            wsprintf(str, TEXT("WM_RBUTTONDOWN Message is Received."));
            MessageBox(hwnd, str, TEXT("Message"), MB_OK);
            break;
        
        /*
        case WM_SETFOCUS:
            wsprintf(str, TEXT("WM_SETFOCUS Message is Received."));
            MessageBox(hwnd, str, TEXT("Message"), MB_OK);
            break;
        
        case WM_KILLFOCUS:
            wsprintf(str, TEXT("WM_KILLFOCUS Message is Received."));
            MessageBox(hwnd, str, TEXT("Message"), MB_OK);
            break;
        */

        case WM_DESTROY:
            wsprintf(str, TEXT("WM_DESTROY Message is Received."));
            MessageBox(hwnd, str, TEXT("Message"), MB_OK);
            // PostQuitMessage(0);
            PostMessage(hwnd, WM_QUIT, 0, 0L);
            break;

        default:
            break;
    }

    return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
// End of WndProc()
