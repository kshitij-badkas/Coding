// csc.exe /T:Winexe CSharpWindow.cs ---> /T Target - GUI based exe not Console based

using System;
using System.Drawing;
using System.Windows.Forms;

public class CSharpWindow : Form
{
    public static void Main()
    {
        Application.Run(new CSharpWindow());
    }

    public CSharpWindow()
    {
        Icon = new Icon("MyIcon.ico");

        Text = "My CSharpWindow";                   // Caption --> CreateWindow's 2nd parameter
        Width = 800;
        Height = 600;

        this.KeyDown += new KeyEventHandler(MyKeyDown);
        this.MouseDown += new MouseEventHandler(MyMouseDown);

        BackColor = Color.Black;                    // hbrBackground
        ResizeRedraw = true;                        // CS_HREDRAW | CS_VREDRAW
    }

    protected override void OnPaint(PaintEventArgs pea)           // WM_PAINT : wParam, lParam
    {
        Graphics grfx = pea.Graphics;


        StringFormat strfmt = new StringFormat();
        strfmt.Alignment = StringAlignment.Center;      // Horizontal center
        strfmt.LineAlignment = StringAlignment.Center;

        grfx.DrawString("Hello, World !!!", 
                        Font,
                        new SolidBrush(Color.Green),
                        ClientRectangle,
                        strfmt);
    }

    void MyKeyDown(object Sender, KeyEventArgs kea)    // WM_KEYDOWN
    {
        MessageBox.Show("A KEY IS PRESSED.");
    }

    void MyMouseDown(object Sender, MouseEventArgs mea)    // WM_''BUTTONDOWN
    {
        MessageBox.Show("A MOUSE BUTTON IS CLICKED.");
    }
}

