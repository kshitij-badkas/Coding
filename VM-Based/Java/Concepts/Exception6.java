import java.util.*;

class AgeInvalid extends Exception
{
	public AgeInvalid(String str)
	{
		super(str);
	}
}

class Exception6
{
	public static void main(String[] args) 
	{
	
		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter first no. : ");
		int age = sobj.nextInt();

		try
		{
			if(age < 18)
			{
				throw new AgeInvalid("Age is below 18");
			}
		}
		catch(AgeInvalid obj)
		{
			System.out.println("Inside catch ");
			System.out.println(obj);
		}
		finally
		{
			System.out.println("Inside finally{} ");
			sobj.close();
		}

		System.out.println("End of application");
	}
}
