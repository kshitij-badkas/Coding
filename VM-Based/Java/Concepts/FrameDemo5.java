//import java.lang.*;
import java.awt.*;
import java.awt.event.*;

class Demo
{
	public String DataDe()
	{
		return "Jay Ganesh...";	
	}
}

class MarvellousFrame extends WindowAdapter implements ActionListener
{
	public Frame fobj;
	public Button bobj;
	public TextField tobj;
	
	public MarvellousFrame(String name)
	{
		fobj = new Frame(name);
		bobj = new Button("Marvellous");
		tobj = new TextField();

		tobj.setBounds(60, 60, 170, 20);
		bobj.setBounds(110, 130, 90, 20);

		fobj.add(bobj);
		fobj.add(tobj);

		fobj.setSize(600, 600);
		fobj.setVisible(true);
		fobj.setLayout(null);

		bobj.addActionListener(this);
		fobj.addWindowListener(this);
	}
	
	public void windowClosing(WindowEvent obj)
	{
		System.exit(0);
	}

	public void actionPerformed(ActionEvent obj)
	{
		System.out.println("Button Clicked");
		Demo dobj = new Demo();
		String str = new String("Jay Ganesh ... ");
		tobj.setText(dobj.DataDe());
	}
}

class FrameDemo5
{
	public static void main(String a[])
	{
		System.out.println("Print data on Console");

		MarvellousFrame mobj = new MarvellousFrame("PPA");
	}
}
