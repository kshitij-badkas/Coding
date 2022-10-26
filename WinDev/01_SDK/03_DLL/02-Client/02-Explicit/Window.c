// Header Files
#include <Windows.h>

#pragma comment(lib, "MyMathTwo.lib")

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
    HMODULE hDLL = NULL;
    typedef int (*MakeCubeFunctionPointer)(int);
    MakeCubeFunctionPointer pfnMakeCube = NULL;
    int iNum = 5;
    int iCube = 0;
    TCHAR str[255];

    // Code
    switch (iMsg)
    {
        case WM_CREATE:
            hDLL = LoadLibrary(TEXT("MyMathTwo.dll"));
            if(hDLL == NULL)
            {
                MessageBox(hwnd, TEXT("LoadLibrary() Failed."), TEXT("Error"), MB_OK);
                DestroyWindow(hwnd);
            }

            pfnMakeCube = (MakeCubeFunctionPointer)GetProcAddress(hDLL, "MakeCube");
            if(pfnMakeCube == NULL)
            {
                MessageBox(hwnd, TEXT("GetProcAddress() Failed."), TEXT("Error"), MB_OK);
                FreeLibrary(hDLL);
                DestroyWindow(hwnd);
            }

            iCube = pfnMakeCube(iNum);
            wsprintf(str, TEXT("Cube of %d is %d"), iNum, iCube);
            MessageBox(hwnd, str, TEXT("Cube"), MB_OK);
            FreeLibrary(hDLL);
            hDLL = NULL;
            DestroyWindow(hwnd);
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
