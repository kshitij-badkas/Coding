import java.util.*;

class Exception1
{
	public static void main(String[] args) 
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Eneter 1st no. : ");
		int no1 = sobj.nextInt();

		System.out.println("Eneter 2nd no. : ");
		int no2 = sobj.nextInt();

		int ans = no1 / no2;

		System.out.println("Division is : "+ans);

		sobj.close();
	}
}
