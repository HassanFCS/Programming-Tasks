import java.sql.*;
import java.util.*;
import java.sql.DriverManager;
import java.lang.*;

public class Acc{

	Connection con;
	Statement st;
	
	Acc() throws Exception
	{
		Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/Account", "root", "Pyrrhic2^");
		st=con.createStatement();
		PreparedStatement pst = con.prepareStatement("SELECT * from Credentials", ResultSet.TYPE_SCROLL_INSENSITIVE, 		ResultSet.CONCUR_UPDATABLE);
	}

	void createAccount() throws Exception
	{

		Scanner inp = new Scanner(System.in);

		System.out.print("Please enter first name: ");
		String FName = inp.nextLine();
		
		System.out.print("Please enter last name: ");
		String LName = inp.nextLine();

		System.out.print("Please enter email address: ");
		String Email = inp.nextLine();

		System.out.print("Please enter password: ");
		String Password= inp.nextLine();

		System.out.print("Please enter gender: ");
		String Gender = inp.nextLine();

		System.out.print("Please enter date of birth: ");
		String DOB = inp.nextLine();
		
		String query="insert into Credentials(FName,LName, Email, PASSWORD, GENDER, DOB) values ('"+FName+"', '"+LName+"','"+Email+"','"+Password+"','"+Gender+"', '"+DOB+"')";

 
     		int ss = st.executeUpdate( query );

	        System.out.println(ss);
   
     		if(ss > 0)
		{
	    		System.out.println("Record inserted successfully.");
	 	}
     
     		else
		{
    	 		System.out.println("Record could not inserted.");
         	}


    	}

	boolean SignIn(String e, String p) throws Exception
	{
		String query="Select * from Credentials";
		ResultSet rs = st.executeQuery( query );
		while(rs.next())
		{
	    		String Email = rs.getString("Email");
    	    		String Password = rs.getString("PASSWORD");
			if(e.equals(Email) && p.equals(Password))
			{
				return true;
			}
	  	}
		return false;
	}

	void updateProfile(String e)
	{
		String query="Select * from Credentials";
		ResultSet rs = st.executeQuery( query );
		Scanner inp = new Scanner(System.in);
		
		while(rs.next())
		{
			if(e.equals(Email))
			{
				System.out.println("What do you wish to update?
						First name: 1
						Last Name: 2
						Password: 3
						Gender: 4
						Date of birth: 5
						}
				int l = inp.nextInt();
				if(l==1)
				{
					System.out.println("Enter new first name: ");
					String a=inp.nextLine();
					rs=st.executeUpdate(
		}
	}

	public static void main(String args[]) throws Exception
	{
		Acc s;
		Scanner inp = new Scanner(System.in);
		s=new Acc();
		s.createAccount();
		System.out.println("Enter email to sign in: ");
		String e = inp.nextLine();
		System.out.println("Enter password to sign in: ");
		String p = inp.nextLine();
		if(s.SignIn(e, p)==true)
		{
			System.out.println("User authentic!");
		}
		else
		{			
    	    		System.out.println("Email and password must match the one entered while signing-up");
		}
	}
}
		