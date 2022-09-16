import java.util.*;

class program202
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Eneter number : ");
        int iValue = sobj.nextInt();

        System.out.println("Eneter Position : ");
        int iPos = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        int iRet = bobj.ToggleBit(iValue, iPos);
        System.out.println("Updated no after toggle is : "+iRet);

    }
}

class Bitwise
{
    public int ToggleBit(int iNo, int iPos)
    {
        if((iPos <= 0) || (iPos > 32))
        {
            System.out.println("Invalid Position.");
            return (0);
        }

        int iMask = 0x00000001;
        int iResult = 0;

        iMask = iMask << (iPos - 1);    // Left Shift

        iResult = iNo ^ iMask;

        return (iResult);
    }
}