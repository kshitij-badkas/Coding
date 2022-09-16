import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.*;

class program291
{
    public static void main(String[] args) 
    {
        try
        {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Please enter exisiting file name : ");
            String fileName = sobj.nextLine();
            
            File fobj = new File(fileName);

            System.out.println("Enter new file to create : ");
            String newFile = sobj.nextLine();

            File fobjNew = new File(newFile);
            boolean bobj1 = fobjNew.createNewFile();
            
            if(fobj.exists())
            {
                FileInputStream fiobj = new FileInputStream(fobj);
                FileOutputStream foobj = new FileOutputStream(fobjNew);

                byte buffer[] = new byte[100];
                int ret = 0;

                while((ret = fiobj.read(buffer)) != -1)
                {
                    foobj.write(buffer, 0, ret);
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
