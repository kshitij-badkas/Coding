import java.io.*;

class Wrapper
{
	public static void main(String args[]) throws IOException
	{
		int no = 11;

		Integer iobj = new Integer(11);

		int i = iobj;				// Unboxing -> Wrapper obj la primitive madhe

		Integer iobj2 = no;			// Boxing -> primitive la Wrapper madhe 

		System.out.println(no);		// 11
		System.out.println(iobj);	// 11
		System.out.println(i);		// 11
		System.out.println(iobj2);	// 11
	}
}
