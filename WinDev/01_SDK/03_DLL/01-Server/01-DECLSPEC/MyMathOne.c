// cl.exe /c /EHsc MyMathOne.c
// link.exe MyMathOne.obj /DLL user32.lib /SUBSYSTEM:WINDOWS

// #include "MyMathOne.h"
#include <Windows.h>

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    // Code
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
            break;

        case DLL_THREAD_ATTACH:
            break;
        
        case DLL_THREAD_DETACH:
            break;

        case DLL_PROCESS_DETACH:
            break;
        
        default:
            break;
    }

    return (TRUE);
}


// int MakeSquare(int num)

// Microsoft Specific Specifier
// Declaration Specific
__declspec(dllexport) int MakeSquare(int num)
{
    // Code
    return (num * num);
}
