import java.lang.*;
import java.util.*;
import MarvellousMatrix.Matrix;

class program335
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number of rows");
        int X = sobj.nextInt();

        System.out.println("Enter number of columns");
        int Y = sobj.nextInt();

        MyMatrix mobj  = new MyMatrix(X,Y);
        
        mobj.Accept();
        System.out.println("Before swap : ");
        mobj.Display();

        System.out.println("After swap : ");
        mobj.SwapRow();
        mobj.Display();

    }
}

class MyMatrix extends Matrix
{
    public MyMatrix(int a, int b)
    {
        super(a,b);
    }

    public void SwapRow()
    {
        int iTemp = 0;

        for(int i = 0; i < iRow-1; i += 2)  // handling the corner cases
        {
            for(int j = 0; j< iCol; j++)
            {
                iTemp = Arr[i][j];
                Arr[i][j] = Arr[i+1][j];
                Arr[i+1][j] = iTemp;
            }
        }
    }
}

