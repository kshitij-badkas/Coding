import java.util.*;

// 0000 0000 0000 0000 0000 0000 0000 1000  
//  0    0    0    0     0    0    0   8
class program200
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Eneter number : ");
        int iValue = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        int iRet = bobj.ToggleBit(iValue);
        System.out.println("Updated no after toggle is : "+iRet);

    }
}

class Bitwise
{
    public int ToggleBit(int iNo)
    {
        // HexaDecimal - 0x
        int iMask = 0x00000008;     // 8 - decimal
        int iResult = iNo ^ iMask;
        return (iResult);
    }
}