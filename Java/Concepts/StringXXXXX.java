import java.io.*;

class StringXXXXX
{
	public static void main(String args[])
	{
		String str1 = "Hello";	//str1 : 100
		String str2 = "Hello";	//str2 : 100
		String str3 = new String("Hello");	//str3 : 200

		if(str1 == str3)	// if(100 == 100)
		{
			System.out.println("Strings are same.");
		}
		else
		{
			System.out.println("Strings are different.");
		}

		if(str1.equals(str3))	// if("Hello".equals("Hello"))
		{		
			System.out.println("Strings are same.");
		}
		else
		{
			System.out.println("Strings are different.");
		}
	}
}
