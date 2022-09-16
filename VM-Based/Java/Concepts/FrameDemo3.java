//import java.lang.*;
import java.awt.*;
import java.awt.event.*;

class MarvellousFrame
{
	public Frame fobj;
	
	public MarvellousFrame(String name)
	{
		fobj = new Frame(name);
		fobj.setSize(600, 600);
		fobj.setVisible(true);

		fobj.addWindowListener(new MarvellousListener());
	} 
}

class MarvellousListener implements WindowListener
{
	public void windowDeactivated(WindowEvent obj){}
	public void windowActivated(WindowEvent obj){}
	public void windowDeiconified(WindowEvent obj){}
	public void windowIconified(WindowEvent obj){}
	public void windowClosed(WindowEvent obj){}

	public void windowClosing(WindowEvent obj)
	{
		System.out.println("Inside windowClosing() ");
		System.exit(0);
	}
	
	public void windowOpened(WindowEvent obj){}
}

class FrameDemo3
{
	public static void main(String a[])
	{
		System.out.println("Print data on Console");

		MarvellousFrame mobj = new MarvellousFrame("PPA");
	}
}
