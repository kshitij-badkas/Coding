// cl.exe /c /EHsc MyMathTwo.c
// link.exe MyMathTwo.obj /DLL /DEF:MyMathTwo.def user32.lib /SUBSYSTEM:WINDOWS

#include "MyMathTwo.h"
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


int MakeCube(int num)
{
    // Code
    return (num * num * num);
}
