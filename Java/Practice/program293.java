import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.*;

class program293
{
    public static void main(String[] args) 
    {
        try
        {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Please enter directory / folder name: ");
            String folderName = sobj.nextLine();
            
            File fobj = new File(folderName);

            File allFiles[] = fobj.listFiles();
            String name;

            for(int i = 0; i < allFiles.length; i++)
            {
                name = allFiles[i].getName();
                if(name.endsWith(".txt"))
                {
                    System.out.println(name);
                }
            }
        }
        catch(Exception obj)
        {
            obj.printStackTrace();
        }
        
    }
}
