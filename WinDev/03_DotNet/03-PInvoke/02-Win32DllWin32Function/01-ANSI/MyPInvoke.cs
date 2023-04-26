// csc.exe MyPInvoke.cs
// MyPInvoke.exe

using System;
using System.Runtime.InteropServices;

public class MyPInvoke
{
    // user32.dll for MessageBoxA()
    [DllImport("user32.dll")] 
        public static extern int MessageBoxA(int handle, String message, String caption, int type);

    public static void Main()
    {
        MessageBoxA(0, "THIS IS 'ANSI' MessageBoxA()", "MESSAGE", 0);
    }
}

