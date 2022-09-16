import java.lang.*;

class Base
{
	public int i;
	public int j;
	
	public Base()
	{
		System.out.println("Inside Base() constructor ");
	}
	
	public void fun()
	{
		System.out.println("Inside Base fun() ");
	}
	
	public void fun(int x)
	{
		System.out.println("Inside Base fun() with integer argument ");
	}
	
	public void gun()
	{
		System.out.println("Inside Base gun() ");
	}
}

class Derived extends Base		// class Derived : public Base
{
	public int x;
	public int y;
	
	public Derived()
	{
		System.out.println("Inside Derived() constructor ");
	}
	
	public void sun()
	{
		System.out.println("Inside Derived sun() ");
	}
}

class Inheritance1
{
	public static void main(String args[])
	{
		Derived dobj = new Derived();
		dobj.fun();
		dobj.fun(11);
		dobj.gun();
		dobj.sun();
		
	}
}
