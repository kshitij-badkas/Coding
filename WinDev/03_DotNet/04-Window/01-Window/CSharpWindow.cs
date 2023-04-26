// csc.exe /T:Winexe CSharpWindow.cs ---> /T Target - GUI based exe not Console based

using System;
using System.Windows.Forms;

public class CSharpWindow : Form
{
    public static void Main()
    {
        Application.Run(new CSharpWindow());
    }

    public CSharpWindow()
    {
        Text = "My CSharpWindow";                   // Caption --> CreateWindow's 2nd parameter
        BackColor = System.Drawing.Color.Black;     // hbrBackground
        ResizeRedraw = true;                      // CS_HREDRAW | CS_VREDRAW
    }
}
