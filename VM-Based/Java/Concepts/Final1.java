import java.lang.*;

class Demo
{
	public int i;
	public final int j = 20;
	public final int k;
	
	public Demo()
	{
		this.i = 10;
		this.k = 30;
	}
	
	public Demo(int i, int k)
	{
		this.i = i;
		this.k = k;
	}
	
	public void fun()
	{
		i++;		// A
		// j++;		// NA
		// k++;		// NA
	}
}

class Final1
{
	public static void main(String args[])
	{
		Demo obj1 = new Demo();
		obj1.fun();
		
		System.out.println(obj1.i);
		System.out.println(obj1.j);
		System.out.println(obj1.k);
		
		Demo obj2 = new Demo(111, 211);
		obj2.fun();
		
		System.out.println(obj2.i);
		System.out.println(obj2.j);
		System.out.println(obj2.k);
	}
}
