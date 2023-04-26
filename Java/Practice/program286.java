import java.io.File;
import java.io.IOException;
import java.util.*;

class program286
{
    public static void main(String[] args) 
    {
        try
        {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Please enter file name : ");
            String fileName = sobj.nextLine();
            
            File fobj = new File(fileName);
            boolean bobj = fobj.createNewFile();
            
            if(bobj == true)
            {
                System.out.println("File opened successfully.");
            }
            else
            {
                System.out.println("File already exists.");
            }
        }
        catch(IOException obj)
        {
            obj.printStackTrace();
        }
        
    }
}
