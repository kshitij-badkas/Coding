import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.*;
import java.util.*;

class Array4_assign_jagged
{
	public static void main(String[] args) 
	{ 
		int i = 0, j = 0, rows = 0, cols = 0;
		
		InputStreamReader iobj = new InputStreamReader(System.in);
		BufferedReader bobj = new BufferedReader(iobj);
		try
		{
			System.out.println("Enter rows : ");
			rows = Integer.parseInt(bobj.readLine());
	
			int arr[][] = new int[rows][];

			for(i = 0; i < rows; i++)
			{
				System.out.println("Enter column size for  row : "+i);
				cols = Integer.parseInt(bobj.readLine());
	
				arr[i] = new int[cols];
				
			}

			for(i = 0; i < arr.length; i++)
			{
				for(j = 0; j < arr[i].length; j++)
				{
					System.out.println("Enter element : row : "+i+ "col : "+j);
					arr[i][j] = Integer.parseInt(bobj.readLine());
				}
			}

			for(i = 0; i < arr.length; i++)
			{
				for(j = 0; j < arr[i].length; j++)
				{
					System.out.println(arr[i][j]);
				}
			}
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
