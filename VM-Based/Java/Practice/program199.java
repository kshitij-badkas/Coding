import java.util.*;

// 0000 0100 0000 0000 0000 0000 0000 0000  
//  0    4    0    0     0    0    0   0
class program199
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Eneter number : ");
        int iValue = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        int iRet = bobj.OnBit(iValue);
        System.out.println("Updated no is : "+iRet);

    }
}

class Bitwise
{
    public int OnBit(int iNo)
    {
        // HexaDecimal - 0x
        int iMask = 0x04000000;     // 6,71,08,864 - decimal
        int iResult = iNo | iMask;
        return (iResult);
    }
}