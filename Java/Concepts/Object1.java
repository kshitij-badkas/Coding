class Employee			// class Emplpyee extends Object
{
	public String name;
	public int Salary;

	public Employee(String str, int no)
	{
		this.name = str;
		this.Salary = no;
	}

	public String toString()
	{
		return name +"->"+Salary;
	}
}

class Object1
{
	public static void main(String args[])
	{
		Employee eobj = new Employee("KAB", 15000);
		System.out.println(eobj.toString());
	}
}
