import java.lang.*;

class Demo
{
	public int i;
	public int j;
	
	public Demo()
	{
		this.i = 0;
		this.j = 0;
	}
	
	public Demo(int x, int y)
	{
		this.i = x;
		this.j = y;
	}
	
	public void fun()
	{
		System.out.println("Inside fun() ");
	}
	
	public void gun()
	{
		System.out.println("Inside gun() ");
	}
}

class Marvellous
{
	public static void main(String arr[])
	{
		System.out.println("Inside main() ");
		
		Demo obj = new Demo();
		obj.fun();		// fun(obj);
		obj.gun();		// gun(obj);
		System.out.println(obj.i);
		System.out.println(obj.j);

		Demo objx = new Demo(11, 21);
		objx.fun();		// fun(objx);
		objx.gun();		// gun(objx);
		System.out.println(objx.i);
		System.out.println(objx.j);
	}
}
