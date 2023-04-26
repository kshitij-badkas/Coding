import java.util.*;

class program348
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter no : ");        
        long iNo = sobj.nextLong();

        long iMask = 0xf000000f;
        long iResult = iNo & iMask;

        if(iResult == iMask)
        {
            System.out.println("First NIBBLE and Last NIBBLE is Completely ON.");
        }
        else
        {
            System.out.println("First NIBBLE and Last NIBBLE is OFF.");
        }
    }
}

