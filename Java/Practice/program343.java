import java.lang.*;
import java.util.*;

// STRINGIZED PATTERN

// Input - 78956 
/*
 * 7 8 9 5 6 
 * 7 8 9 5 6 
 * 7 8 9 5 6 
 * 7 8 9 5 6 
 * 7 8 9 5 6 
 * 7 8 9 5 6 
 */
class program343
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter no : ");
        int no = sobj.nextInt();

        // String str = Integer.toString(no);

        char Arr[] = Integer.toString(no).toCharArray();

        for(int i = 0; i < Arr.length; i++)
        {
            for(int j = 0; j < Arr.length; j++)
            {
                System.out.print(Arr[j] + " ");
            }
            System.out.println();
        }

    }
}

