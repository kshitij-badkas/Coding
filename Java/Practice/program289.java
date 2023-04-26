import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.*;

class program289
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
                FileInputStream fiobj = new FileInputStream(fobj);
                byte buffer[] = new byte[100];
                int ret = 0;
                int sum = 0;

                while((ret = fiobj.read(buffer)) != -1)
                {
                    sum = sum + ret;
                    String str = new String(buffer, StandardCharsets.UTF_8);
                    System.out.println(str);
                }
                // System.out.println("Data read : "+sum);
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
