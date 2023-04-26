// cl.exe /c /EHsc Window.cpp
// rc.exe Window.rc
// link.exe Window.obj Window.res user32.lib gdi32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS

// Header Files
#include "Window.h"

#import "DotNetServer.tlb" no_namespace named_guids raw_interfaces_only // 

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
    IDispatch *pIDispatch = NULL;
    HRESULT hr;

    // OLECHAR - a.k.a - B Str - Binary String or Basic String
    // Ole chya char string la B Str - Binary String
    OLECHAR *szFunctionName1 = L"SumOfTwoIntegers";             // L - Literal Character
    OLECHAR *szFunctionName2 = L"SubtractionOfTwoIntegers";     // L - Literal Character
    VARIANT vArg[2];
    VARIANT vResult;
    DISPID dispid;
    DISPPARAMS params;


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

            hr = CoCreateInstance(CLSID_DotNetServer, 
                                    NULL, 
                                    CLSCTX_INPROC_SERVER, 
                                    IID_IDispatch, 
                                    (void **)&pIDispatch);

            if(FAILED(hr))
            {
                MessageBox(hwnd, TEXT("CoCreateInstance Failed To Get IDispatch Interface"), TEXT("Error"), MB_OK);
                DestroyWindow(hwnd);
            }

            num1 = 275;
            num2 = 225;

            // Get ID of SumOfTwoIntegers()
            hr = pIDispatch->GetIDsOfNames(IID_NULL, 
                                            &szFunctionName1,
                                            1,  // as second parameter is array but we have only one element - hence, 1 count
                                            GetUserDefaultLCID(), 
                                            &dispid);

            if(FAILED(hr))
            {
                wsprintf(str, TEXT("Failed to get GetIDsOfNames()"));
                MessageBox(hwnd, str, TEXT("Error"), MB_OK);                
                pIDispatch->Release();
                pIDispatch = NULL;
                DestroyWindow(hwnd);
            }


            // CAll SumOfTwoIntegers() by passing its ID to Invoke()
            VariantInit(vArg);
            vArg[0].vt = VT_INT;    // variant type Integer
            vArg[0].intVal = num2;  // pascal calling convention  
            vArg[1].vt = VT_INT;
            vArg[1].intVal = num1;
            VariantInit(&vResult);
            params.rgvarg = vArg;
            params.cArgs = 2;
            params.rgdispidNamedArgs = NULL;
            params.cNamedArgs = 0;
            hr = pIDispatch->Invoke(dispid,
                                    IID_NULL,
                                    GetUserDefaultLCID(),
                                    DISPATCH_METHOD,
                                    &params,
                                    &vResult,
                                    NULL,
                                    NULL);

            sum = vResult.lVal;
            wsprintf(str, TEXT("Sum of %d and %d = %d"), num1, num2, sum);
            MessageBox(hwnd, str, TEXT("Sum"), MB_OK);

            // Get ID of SubtractionOfTwoIntegers()
            hr = pIDispatch->GetIDsOfNames(IID_NULL, 
                                            &szFunctionName2,
                                            1,  // as second parameter is array but we have only one element - hence, 1 count
                                            GetUserDefaultLCID(), 
                                            &dispid);

            if(FAILED(hr))
            {
                wsprintf(str, TEXT("Failed to get GetIDsOfNames()"));
                MessageBox(hwnd, str, TEXT("Error"), MB_OK);                
                pIDispatch->Release();
                pIDispatch = NULL;
                DestroyWindow(hwnd);
            }


            // CAll SubtractionOfTwoIntegers() by passing its ID to Invoke()
            VariantInit(vArg);
            vArg[0].vt = VT_INT;    // variant type Integer
            vArg[0].intVal = num2;  // pascal calling convention  
            vArg[1].vt = VT_INT;
            vArg[1].intVal = num1;
            VariantInit(&vResult);
            params.rgvarg = vArg;
            params.cArgs = 2;
            params.rgdispidNamedArgs = NULL;
            params.cNamedArgs = 0;
            
            hr = pIDispatch->Invoke(dispid,
                                    IID_NULL,
                                    GetUserDefaultLCID(),
                                    DISPATCH_METHOD,
                                    &params,
                                    &vResult,
                                    NULL,
                                    NULL);

            sub = vResult.lVal;
            wsprintf(str, TEXT("Subtraction of %d and %d = %d"), num1, num2, sub);
            MessageBox(hwnd, str, TEXT("Sum"), MB_OK);

            VariantClear(&vResult);
            VariantClear(vArg);
            pIDispatch->Release();
            pIDispatch = NULL;
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
