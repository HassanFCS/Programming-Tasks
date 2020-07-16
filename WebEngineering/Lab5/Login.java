import java.sql.*;
import java.util.*;

class Profile{

    // data members
    Connection con;
    Statement st;

    
    Profile() throws Exception {
        Class.forName("com.mysql.jdbc.Driver");
        String url = "jdbc:mysql://127.0.0.1/lab";
        con = DriverManager.getConnection(url,"root","root");
        st = con.createStatement();
    }

    public void signUp(String fname, String lname, String email, String pass, String gender, String dob) throws Exception {
        String query = "insert into info(FirstName,LastName,Email,Password,Gender,DOB) values('"+fname+"','"+lname+"','"+email+"','"+pass+"','"+gender+"','"+dob+"')";
        int rs = st.executeUpdate( query );

        if(rs > 0){
            System.out.println("Sign UP successfully.");
        }
        else{
             System.out.println("Some Error occure.. try again later.....");
        }
    
    }

    public void signIn(String u_email, String u_pass) throws Exception {
        String query="Select * from info where email='"+u_email+"' ";
        ResultSet rs = st.executeQuery( query );
    
        if(rs.next()){
            if(u_pass.equals(rs.getString("pass")))
                    System.out.println("Sign IN successful.....");
            else
                System.out.println("Error occur,,, try again later....");
        }
    }

    public void update(String u_email) throws Exception {
        String query="Select * from info where email='"+u_email+"' ";
        ResultSet rs = st.executeQuery( query );
    
        if(rs.next()){
            Scanner inp = new Scanner(System.in);
            System.out.print("Please enter First Name: ");
            String fname = inp.nextLine();

            System.out.print("Please enter Last Name: ");
            String lname = inp.nextLine();
        
            System.out.print("Please enter Password: ");
            String pass= inp.nextLine();
            
            System.out.print("Please enter Gender: ");
            String gender= inp.nextLine();
            
            System.out.print("Please enter Date of Brith: ");
            String dob= inp.nextLine();
            

            String query2 = "UPDATE info set FirstName = "+fname+",LastName = "+lname+",Password = "+pass+",Gender = "+gender+",DOB = "+dob+" where Email = '"+u_email+"')";
            int rs2 = st.executeUpdate( query2 );

            if(rs2 > 0){
                System.out.println("Record updated successfully.");
            }
            else{
                System.out.println("Record could not inserted.");
            }   

        }
        else{
            System.out.println("No record found");
        }
    }
}

public class Login{
    public static void main(String[] args) throws Exception {
        int  ch;
        Scanner in = new Scanner(System.in);
        Profile user = new Profile();

        System.out.println("1- Signup\n
            2- Signin\n
            3- Update\n
            4- Exit\n");
        System.out.println("Enter your Choice:");

        ch = in.nextInt();

        String fname, lname, email, pass, gender, dob, u_email;

        switch(ch){
            case 1:
                Scanner inp = new Scanner(System.in);

                System.out.print("Please enter First Name: ");
                fname = inp.nextLine();

                System.out.print("Please enter Last Name: ");
                lname = inp.nextLine();
            
                System.out.print("Please enter Email: ");
                email = inp.nextLine();
            
                System.out.print("Please enter Password: ");
                pass= inp.nextLine();
                
                System.out.print("Please enter Gender: ");
                gender= inp.nextLine();
                
                System.out.print("Please enter Date of Brith: ");
                dob= inp.nextLine();
                
                user.signUp(fname, lname, email, pass, gender, dob);
                break;

            case 2:
                System.out.print("Please enter your Email: ");
                u_email = in.nextLine();

                System.out.print("Please enter your Password: ");
                String u_pass = in.nextLine();
                
                user.signIn(u_email, u_pass);
                
                break;
            
            case 3:
                System.out.print("Please enter your Email: ");
                u_email = in.nextLine();
                
                user.update(u_email);
                
                break;
            
            case 4:
                System.exit(0);
                break;
        }
    }
}