import java.util.*;
import java.io.*;

class program299
{
    public static void main(String arg[])
    {
        try
        {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Please enter packed file name");
            String packFileName = sobj.nextLine();

            File fobj = new File(packFileName);

            FileInputStream fiobj = new FileInputStream(fobj);
            byte headerArray[] = new byte[100];

            fiobj.read(headerArray, 0, 100);

            String headerString = new String(headerArray);
            System.out.println(headerString);

            String tokens[] = headerString.split(" ");
            System.out.println("File name : " +tokens[0]);
            System.out.println("File size : " +tokens[1]);

            File fobjNew = new File(tokens[0]);
            boolean bobj = fobjNew.createNewFile();

            

        }
        catch(Exception obj)
        {
            System.out.println(obj);
        }

    }
}