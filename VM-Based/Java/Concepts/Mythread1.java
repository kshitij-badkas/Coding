class Mythread1
{
	public static void main(String args[])
	{
		System.out.println("Inside main ()");

		Thread tobj = Thread.currentThread();	// tobj is reference

		System.out.println("Name of current thread is : "+tobj.getName());
	}
}
