import java.util.*;

// 0000 0000 0000 0000 0010 0000 0000 0000  
//  0    0    0    0     2    0    0    0
class program197
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
        int iMask = 0x00002000;     // 8192 - decimal
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