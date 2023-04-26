import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

class program288
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
                BufferedReader bobj = new BufferedReader(new FileReader(fobj));
                String str;

                while((str = bobj.readLine()) != null)
                {
                    System.out.println(str);
                }
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
