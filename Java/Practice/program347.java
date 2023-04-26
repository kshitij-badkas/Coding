import java.util.*;

class program347
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter no : ");        
        int iNo = sobj.nextInt();

        int iMask = 0x0000000f;
        int iResult = iNo & iMask;

        if(iResult == iMask)
        {
            System.out.println("First NIBBLE is Completely ON.");
        }
        else
        {
            System.out.println("First NIBBLE is OFF.");
        }
    }
}

