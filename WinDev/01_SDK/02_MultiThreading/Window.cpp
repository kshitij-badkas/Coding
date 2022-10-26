// Header Files
#include <Windows.h>

// Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// *
DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID);

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
    
    // *
    HDC hdc;
    HANDLE hThread1 = NULL;
    HANDLE hThread2 = NULL;
    TCHAR str[255];
    int i;

    // Code
    switch (iMsg)
    {
        // *
        case WM_CREATE:
            hThread1 = CreateThread(
                NULL,
                0,
                (LPTHREAD_START_ROUTINE)ThreadProcOne,
                (LPVOID)hwnd, 
                0,
                NULL);

            hThread2 = CreateThread(
                NULL,
                0,
                (LPTHREAD_START_ROUTINE)ThreadProcTwo,
                (LPVOID)hwnd,
                0,
                NULL);

            break;

        // *
        case WM_LBUTTONDOWN:
            MessageBox(hwnd, TEXT("This is my Message Box"), TEXT("Message"), MB_OK);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        
        default:
            break;
    }

    return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
// End of WndProc()

// *
DWORD WINAPI ThreadProcOne(LPVOID param)
{
    // variable decalartaoins
    HDC hdc;
    TCHAR str[255];
    long i;

    // code
    hdc = GetDC((HWND)param);
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, RGB(255, 255, 0));

    for(i = 0; i < LONG_MAX; i++)
    {
        wsprintf(str, TEXT("Numbers in Incrementing Order : %ld"), i);
        TextOut(hdc, 5, 5, str, wcslen(str));
    }

    ReleaseDC((HWND)param, hdc);

    return (0);
}

// *
DWORD WINAPI ThreadProcTwo(LPVOID param)
{
    // variable decalartaoins
    HDC hdc;
    TCHAR str[255];
    long i;

    // code
    hdc = GetDC((HWND)param);
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, RGB(0, 255, 255));

    for(i = LONG_MAX; i >= 0; i--)
    {
        wsprintf(str, TEXT("Numbers in Decrementing Order : %ld"), i);
        TextOut(hdc, 5, 20, str, wcslen(str));
    }

    ReleaseDC((HWND)param, hdc);

    return (0);
}