import java.lang.*;
import java.util.*;

// STRINGIZED PATTERN

// Input - Hello 
/*
 * H
 * H e
 * H e l
 * H e l l
 * H e l l o 
 * H e l l 
 * H e l
 * H e
 * H
 */
class program341
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter String : ");
        String str = sobj.nextLine();

        char Arr[] = str.toCharArray();

        for(int i = 0; i < Arr.length-1; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                System.out.print(Arr[j] + " ");
            }
            System.out.println();
        }

        for(int i = Arr.length-1; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                System.out.print(Arr[j] + " ");
            }
            System.out.println();
        }

    }
}

