import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.*;
import java.util.*;

class Array_assign_largest
{
	public static void main(String[] args) 
	{ 
		int i = 0, iNo = 0;
		
		InputStreamReader iobj = new InputStreamReader(System.in);
		BufferedReader bobj = new BufferedReader(iobj);
		try
		{
			System.out.println("Enter number : ");
			iNo = Integer.parseInt(bobj.readLine());
	
			int arr[] = new int[iNo];

			for(i = 0; i < iNo; i++)
			{
				System.out.println("Enter element : "+i);
				arr[i] = Integer.parseInt(bobj.readLine());				
			}

			for(i = 0; i < arr.length; i++)
			{
				//Logic
			}

			System.out.println("Largest : ");
		}
		catch(IOException e)
		{
			System.out.println("Exception occurred : "+e);
		}
		finally
		{
			iobj = null;
			bobj = null;
		}
	}
}
