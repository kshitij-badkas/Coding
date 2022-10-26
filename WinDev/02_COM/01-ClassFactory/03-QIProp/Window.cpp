// cl.exe /c /EHsc Window.cpp
// rc.exe Window.rc
// link.exe Window.obj Window.res user32.lib gdi32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS
// double click .reg -> Not Required   //*
// run .exe     //*

// Header Files
#include <Windows.h>
#include "Window.h"
#include "ClassFactoryDllServerWithRegFile.h"

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
    // Local Variable Declaration
    ISum *pISum = NULL;
    ISubtract *pISubtract = NULL;
    IUnknown *pIUnknownFromISum = NULL; //*
    IUnknown *pIUnknownFromISubtract = NULL; //*
    ISum *pISumAgain = NULL; //*
    HRESULT hr;
    int n1, n2, sum, subtract;
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

            n1 = 55;
            n2 = 45;
            pISum->SumOfTwoIntegers(n1, n2, &sum);
            wsprintf(str, TEXT("Sum of %d & %d is %d"), n1, n2, sum);
            MessageBox(hwnd, str, TEXT("Sum"), MB_OK);

            pISum->QueryInterface(IID_ISubtract, (void **)&pISubtract);
            pISubtract->SubtractionOfTwoIntegers(n1, n2, &subtract);
            wsprintf(str, TEXT("Subtraction of %d & %d is %d"), n1, n2, subtract);
            MessageBox(hwnd, str, TEXT("Subtraction"), MB_OK);

            //* 
            // Identity
            pISum->QueryInterface(IID_IUnknown, (void**)&pIUnknownFromISum);
            pISubtract->QueryInterface(IID_IUnknown, (void **)&pIUnknownFromISubtract);
            if(pIUnknownFromISum == pIUnknownFromISubtract)
            {
                wsprintf(str, TEXT("Identity Is Proven."));
                MessageBox(hwnd, str, TEXT("QIProp - Identity"), MB_OK);
            }

            //*
            // Predicatibility
            if(pISum)
            {
                pISum->Release();
                pISum = NULL;
                wsprintf(str, TEXT("pISum is Released Successfully."));
                MessageBox(hwnd, str, TEXT("QIProp - Predicability"), MB_OK);
            }
            Sleep(5000);   // 5 seconds
            pISubtract->QueryInterface(IID_ISum, (void**)&pISum);
            pISum->SumOfTwoIntegers(n1, n2, &sum);
            wsprintf(str, TEXT("Sum of %d & %d is %d\nPredicability Is Proven."), n1, n2, sum);
            MessageBox(hwnd, str, TEXT("QIProp - Predicability"), MB_OK);

            //* 
            // Reflexivity
            pISum->QueryInterface(IID_ISum, (void**)&pISumAgain);
            if(pISum == pISumAgain)
            {
                wsprintf(str, TEXT("Reflexivity Is Proven."));
                MessageBox(hwnd, str, TEXT("QIProp - Reflexivity"), MB_OK);
            }
            if(pISumAgain)
            {
                pISumAgain->Release();
                pISumAgain = NULL;
            }

            //* 
            // Symmetry
            pISum->QueryInterface(IID_ISubtract, (void**)&pISubtract);
            pISubtract->QueryInterface(IID_ISum, (void**)&pISumAgain);
            if(pISum == pISumAgain)
            {
                wsprintf(str, TEXT("Symmetry Is Proven."));
                MessageBox(hwnd, str, TEXT("QIProp - Symmetry"), MB_OK);
            }

            // Safe Release
            if(pISumAgain)
            {
                pISumAgain->Release();
                pISumAgain = NULL;
            }
            if(pISubtract)
            {
                pISubtract->Release();
                pISubtract = NULL;
            }
            if(pISum)
            {
                pISum->Release();
                pISum = NULL;
            }

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
