import java.io.File;
import java.io.IOException;
import java.util.*;

class program287
{
    public static void main(String[] args) 
    {
        try
        {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Please enter file name : ");
            String fileName = sobj.nextLine();
            
            File fobj = new File(fileName);
            
            if(fobj.exists())
            {
                long size = fobj.length();
                System.out.println("File length is : "+ size);
            }
            else
            {
                System.out.println("There is no such file.");
            }
        }
        catch(Exception obj)
        {
            obj.printStackTrace();
        }
        
    }
}
