// cl.exe /c /EHsc Window.cpp
// rc.exe Window.rc
// link.exe Window.obj Window.res user32.lib gdi32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS
// double click .reg -> Yes
// run .exe

// Header Files
#include <Windows.h>
#include "Window.h"
#include "ClientOfContainmentComponentWithRegFile.h"

// Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable Declarations
ISum *pISum = NULL;
ISubtract *pISubtract = NULL;
IMultiplication *pIMultiplication = NULL;
IDivision *pIDivision = NULL;

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // Local Variable Declaration
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("WINDEV");

    HRESULT hr;
    
    // Code
    // COM Initialization      
    hr = CoInitialize(NULL);    
    if(FAILED(hr))            
    {
        MessageBox(NULL, TEXT("COM Initialization Failed."), TEXT("Error"), MB_OK);    
        exit(0);        
    }

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

    // COM Uninitialization
    CoUninitialize();

    return((int)msg.wParam);
}
// End of WinMain()

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // function declaration
    void SafeInterfaceRelease(void);

    // Local Variable Declaration
    HRESULT hr;
    int iNum1, iNum2, iSum, iSubtraction, iMultiplication, iDivision;
    TCHAR str[255];

    // Code
    switch (iMsg)
    {
        case WM_CREATE:
            hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void **)&pISum);
            if(FAILED(hr))
            {
                MessageBox(hwnd, TEXT("ISum() Cannot be Obtained."), TEXT("Error"), MB_OK);
                DestroyWindow(hwnd);
            }

            iNum1 = 65;
            iNum2 = 45;
            pISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);
            wsprintf(str, TEXT("Sum of %d & %d is %d"), iNum1, iNum2, iSum);
            MessageBox(hwnd, str, TEXT("Sum"), MB_OK);
            hr = pISum->QueryInterface(IID_ISubtract, (void **)&pISubtract);
            if(FAILED(hr))
            {
                MessageBox(hwnd, TEXT("ISubtract() Cannot be Obtained."), TEXT("Error"), MB_OK);
                DestroyWindow(hwnd);
            }
            pISum->Release();
            pISum = NULL;
            
            iNum1 = 155;
            iNum2 = 55;
            pISubtract->SubtractionOfTwoIntegers(iNum1, iNum2, &iSubtraction);
            wsprintf(str, TEXT("Subtraction of %d & %d is %d"), iNum1, iNum2, iSubtraction);
            MessageBox(hwnd, str, TEXT("Subtraction"), MB_OK);
            hr = pISubtract->QueryInterface(IID_IMultiplication, (void **)&pIMultiplication);
            if(FAILED(hr))
            {
                MessageBox(hwnd, TEXT("IMultiplication() Cannot be Obtained."), TEXT("Error"), MB_OK);
                DestroyWindow(hwnd);
            }
            pISubtract->Release();
            pISubtract = NULL;

            iNum1 = 30;
            iNum2 = 25;
            pIMultiplication->MultiplicationOfTwoIntegers(iNum1, iNum2, &iMultiplication);
            wsprintf(str, TEXT("Multiplication of %d & %d is %d"), iNum1, iNum2, iMultiplication);
            MessageBox(hwnd, str, TEXT("Multiplication"), MB_OK);
            hr = pIMultiplication->QueryInterface(IID_IDivision, (void **)&pIDivision);
            if(FAILED(hr))
            {
                MessageBox(hwnd, TEXT("IDivision Cannot be Obtained."), TEXT("Error"), MB_OK);
                DestroyWindow(hwnd);
            }
            pIMultiplication->Release();
            pIMultiplication = NULL;

            iNum1 = 200;
            iNum2 = 25;
            pIDivision->DivisionOfTwoIntegers(iNum1, iNum2, &iDivision);
            wsprintf(str, TEXT("Division of %d & %d is %d"), iNum1, iNum2, iDivision);
            MessageBox(hwnd, str, TEXT("Division"), MB_OK);
            pIDivision->Release();
            pIDivision = NULL;

            DestroyWindow(hwnd);
            break;


        case WM_DESTROY:
            SafeInterfaceRelease();
            PostQuitMessage(0);
            break;
        
        default:
            break;
    }

    return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
// End of WndProc()

void SafeInterfaceRelease(void)
{
    // code
    if(pISum)
    {
        pISum->Release();
        pISum = NULL;
    }
    if(pISubtract)
    {
        pISubtract->Release();
        pISubtract = NULL;
    }
    if(pIMultiplication)
    {
        pIMultiplication->Release();
        pIMultiplication = NULL;
    }
    if(pIDivision)
    {
        pIDivision->Release();
        pIDivision = NULL;
    }
}
