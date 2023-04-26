import java.util.*;

class program196
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Eneter number : ");
        int iValue = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        boolean bRet = bobj.CheckBit(iValue);

        if(bRet == true)
        {
            System.out.println("Bit is ON");
        }
        else
        {
            System.out.println("Bit is OFF");
        }
    }
}

class Bitwise
{
    public boolean CheckBit(int iNo)
    {
        // HexaDecimal - 0x
        int iMask = 0x00100000;     // 1048576 - decimal
        int iRes = iNo & iMask;
        {
            if(iRes == 0)
            {   
                return (false);
            }
            else
            {
                return (true);
            }
        }
    }
}