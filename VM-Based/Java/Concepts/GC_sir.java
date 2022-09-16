import java.lang.*;

class Demo
{
    public int Arr[];

    public Demo(int size)
    {
        System.out.println("Allocating the resources in constructor");
        this.Arr = new int[size];
    }

    protected void finalize()
    {
        System.out.println("Deallocating the resources in finalize");
        this.Arr = null;
    }
}
class GC_sir
{
    public static void main(String arg[])
    {
        Demo dobj = new Demo(10);
        dobj = null;
        System.gc();
        System.out.println("End of main");
    }
}