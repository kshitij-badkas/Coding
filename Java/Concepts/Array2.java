import java.lang.*;
import java.util.*;

class Array2
{
	public static void main(String[] args) 
	{
		int iCnt = 0;
		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter no. of elements : ");
		int size = sobj.nextInt();

		int Arr[] = new int[size];
		
		System.out.println("Enter elements of array : ");
		for(iCnt = 0; iCnt < Arr.length; iCnt++)
		{
			Arr[iCnt] = sobj.nextInt();
		}

		System.out.println("Elements of array are: ");
		for(iCnt = 0; iCnt < Arr.length; iCnt++)
		{
			System.out.println(Arr[iCnt]);
		}
	}
}
