import java.sql.*;  // 1

class Database
{
    public static void main(String a[])
    {
        try
        {
            Class.forName("com.mysql.jdbc.Driver");     // 2
            System.out.println("Inside Class.forName() ");

            Connection con = DriverManager.getConnection("jbdc::mysql://localhost:3306/marvellous", "root", "root"); // 3
            System.out.println("Inside DriverManager.getConnection() ");

            Statement stmt = con.createStatement(); // 4
            System.out.println("Inside con.createStatement() ");

            ResultSet rs = stmt.executeQuery("select * from student");  // 5
            System.out.println("Inside stmt.executeQuery() ");

            while(rs.next())    // 6
            {
                System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getInt(3) + " " + rs.getString(4));
            }

            con.close();

        }
        catch(Exception e)
        {
            System.out.println("Esception occurred : "+e);
        }
    }
}
