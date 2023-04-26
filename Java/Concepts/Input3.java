import java.io.*;

class Input3
{
	public static void main(String args[])
	{
		InputStreamReader iobj = new InputStreamReader(System.in);
		BufferedReader bobj = new BufferedReader(iobj);

		// CHECKED EXCEPTION
		try
		{
			System.out.println("Enter string : ");
			String str = bobj.readLine();

			System.out.println("Enter integer : ");
			int no = Integer.parseInt(bobj.readLine());

			System.out.println("Enter float : ");
			float f = Float.parseFloat(bobj.readLine());

			System.out.println("Enter double : ");
			double d = Double.parseDouble(bobj.readLine());

			System.out.println("string is : "+str);
			System.out.println("integer is : "+no);
			System.out.println("float is : "+f);
			System.out.println("double is : "+d);
		}
		catch(IOException obj)
		{
			System.out.println("Exception occurred : "+obj);
		}
		finally
		{
			iobj = null;
			bobj = null;
		}
	}
}
