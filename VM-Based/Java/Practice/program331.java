import java.util.*;

import MarvellousMatrix.Matrix;

class program331
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number of rows : ");
        int X = sobj.nextInt();

        System.out.println("Enter number of columns : ");
        int Y = sobj.nextInt();

        Matrix mobj = new Matrix(X, Y);

        mobj.Accept();
        mobj.Display();

    }
}
