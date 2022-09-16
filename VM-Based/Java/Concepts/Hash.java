class Demo
{}

class Hash
{
	public static void main(String args[]) throws Exception
	{
		String str1 = "Marvellous";		// string literal
		String str2 = "Marvellous";		// string literal
		String str3 = "Infosystems";	// string literal
		Demo dobj = new Demo();			// object

		System.out.println("Hashcode of str1 : "+str1.hashCode());
		System.out.println("Hashcode of str2 : "+str2.hashCode());
		System.out.println("Hashcode of str3 : "+str3.hashCode());
		System.out.println("Hashcode of dobj : "+dobj.hashCode());
	}
}
