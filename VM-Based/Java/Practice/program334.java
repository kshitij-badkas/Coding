import java.lang.*;
import java.util.*;
import MarvellousMatrix.Matrix;

class program334
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
        mobj.Display();

        int iRet = mobj.Maximum();
        System.out.println("Maximum element is : "+iRet);

        iRet = mobj.Minimum();
        System.out.println("Minimum element is : "+iRet);
    }
}

class MyMatrix extends Matrix
{
        public MyMatrix(int a, int b)
        {
            super(a,b);
        }

        public int Maximum()
        {
            int iMax = Arr[0][0];

            for(int i = 0; i < iRow; i++)
            {
                for(int j =0; j< iCol; j++)
                {
                    if(Arr[i][j] > iMax)
                    {
                        iMax = Arr[i][j];
                    }
                }
            }
            return iMax;
        }

        public int Minimum()
        {
            int iMin = Arr[0][0];

            for(int i = 0; i < iRow; i++)
            {
                for(int j =0; j< iCol; j++)
                {
                    if(Arr[i][j] < iMin)
                    {
                        iMin = Arr[i][j];
                    }
                }
            }
            return iMin;
        }
}
