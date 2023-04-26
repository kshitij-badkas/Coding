import java.lang.*;

class Base
{
	public int i, j;
	
	public void fun()		// Definition
	{
		System.out.println("Base fun() ");
	}
	
	public void gun()		// Definition
	{
		System.out.println("Base gun() ");
	}
	
	public void sun()		// Definition
	{
		System.out.println("Base sun() ");
	}
}

class Derived extends Base
{
	public int x, y;
	
	public void fun()		// Overriding (Redefinition - C++)
	{
		System.out.println("Derived fun() ");
	}
	
	public void sun()		// Overriding (Redefinition - C++)
	{
		System.out.println("Derived sun() ");
	}
	
	public void run()		// Definition
	{
		System.out.println("Derived run() ");
	}
}

class Virtual
{
	public static void main(String args[])
	{
		// Base bobj = new Base();			// No casting
		// Derived dobj = new Derived();	// No casting
		
		Base obj = new Derived();			// Upcasting	// base *bp = new Derived()
		// Derived obj2 = new Base(); 		// Downcasting
		
		obj.fun();	// Derived fun		bp->fun();
		obj.gun();	// Base gun
		obj.sun();	// Dervied sun
		// obj.run();
	}
}
