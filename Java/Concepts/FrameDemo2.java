//import java.lang.*;
import java.awt.*;

class MarvellousFrame
{
	public Frame fobj;
	
	public MarvellousFrame(String name)
	{
		fobj = new Frame(name);
		fobj.setSize(600, 600);
		fobj.setVisible(true);
	} 
}

class FrameDemo2
{
	public static void main(String a[])
	{
		System.out.println("Print data on Console");

		MarvellousFrame mobj = new MarvellousFrame("PPA");
	}
}
