// 1.  csc.exe /T:Library DotNetServer.cs ---> x4 cmd.
// 2.  regasm.exe DotNetServer.dll /tlb ---> RUN AS ADMIN x64 cmd.

// oleview.exe => "C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x64\oleview.exe" ---> RUN AS ADMIN

using System;

public class DotNetServer
{
    public int SumOfTwoIntegers(int num1, int num2)
    {
        return (num1 + num2);
    }

    public int SubtractionOfTwoIntegers(int num1, int num2)
    {
        return (num1 - num2);
    }

}
