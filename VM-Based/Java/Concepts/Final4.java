import java.lang.*;

final class Base
{
	public void fun()
	{
		System.out.println("Base fun() ");
	}
}

class Derived
{
	public Base bobj = new Base();		// COMPOSITION
	
	public void gun()
	{
		System.out.println("Derived gun() ");
	}
}

class Final4
{
	public static void main(String args[])
	{
		Derived dobj = new Derived();
		
		dobj.bobj.fun();
		
		dobj.gun();
	}
}
