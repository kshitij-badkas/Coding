// csc.exe MyPInvoke.cs
// MyPInvoke.exe

// UNICODE

using System;
using System.Runtime.InteropServices;

public class MyPInvoke
{
    [DllImport("user32.dll", CharSet = CharSet.Unicode)] 
        public static extern int MessageBoxW(int handle, String message, String caption, int type);

    public static void Main()
    {
        MessageBoxW(0, "THIS IS 'UNICODE' MessageBoxW()", "MESSAGE", 0);
    }
}
