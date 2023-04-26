// cl.exe /clr Hybrid.cpp
// "/clr switch tells CLR to separate Native ++ and Dot Net Managed C++ --> Safe and Unsafe"
// "/clr switch is available since cl.exe version 13 and above."

#include <stdio.h>
#using <MSCorLib.dll>
using namespace System;

int main(void)
{
    printf("This Line is From Native C++\n");
    
    Console::WriteLine("This Line is From Dot Net Managed C++\n");

    return (0);
}
