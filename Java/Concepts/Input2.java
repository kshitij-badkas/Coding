import java.lang.*;
import java.io.*;

class Input2
{
	public static void main(String args[])
	{
		InputStreamReader iobj = new InputStreamReader(System.in);
		BufferedReader bobj = new BufferedReader(iobj);

		// CHECKED EXCEPTION
		try
		{
			System.out.println("Enter your name : ");
			String name = bobj.readLine();
			System.out.println("Your name is : "+name);

			System.out.println("Enter your age : ");
			int age = Integer.parseInt(bobj.readLine());
			System.out.println("Your name is : "+age);
		}
		catch(IOException obj)
		{
			System.out.println("Exception occurred : "+obj);
		}
		finally
		{
			// iobj.close();
			// bobj.close();
			iobj = null;
			bobj = null;
		}
	}
}
