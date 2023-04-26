import java.lang.*;

abstract class RBI
{
	public int Balance;
	
	public RBI()
	{
		this.Balance = 0;
	}
	
	public void Credit(int Amount)
	{
		this.Balance = this.Balance + Amount;
	}
	
	public void Debit(int Amount)
	{
		this.Balance = this.Balance - Amount;
	}
	
	public abstract int CalculateInterest();
}

class SBI extends RBI
{
	public int AccountNumber;
	public int IFSC;
	
	public int CalculateInterest()
	{
		return (6);
	}
	
}

class PNB extends RBI
{
	public int AccountNumber;
	public int IFSC;
	
	public int CalculateInterest()
	{
		return (7);
	}
}

class AbstractDemo
{
	public static void main(String args[])
	{
		PNB pobj = new PNB();
		SBI sobj = new SBI();
		
		pobj.Credit(1000);
		pobj.Debit(200);
		
		System.out.println(pobj.Balance); 		// 800
	}
}
