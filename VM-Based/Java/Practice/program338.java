import java.lang.*;
import java.util.*;

// STRINGIZED PATTERN

// Input - Hello 
/*
 * 
 * 
 * 
 */
class program337
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter String : ");
        String str = sobj.nextLine();

        char Arr[] = str.toCharArray();

        for(int i = 0; i < Arr.length; i++)
        {
            for(int j = 0; j < Arr.length; j++)
            {
                System.out.print(Arr[i] + " ");
            }
            System.out.println();
        }

    }
}

