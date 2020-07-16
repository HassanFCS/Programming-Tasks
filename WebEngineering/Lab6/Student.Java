import java.sql.*;
import java.util.*;

public class Student{

	// data members
	Connection Con;
	Statement Stat;
	String name;
	String rollNumber;
	int cNIC;
	String degree;
	String gender;
	int mobile;

    
	Student() throws Exception {
		Class.forName("com.mysql.jdbc.Driver");
        	String url = "jdbc:mysql://127.0.0.1/lab";
        	Con = DriverManager.getConnection(url,"root","root");
     		Stat = Con.createStatement();
    	}
	
	public void PrintAll() throws Exception {
        	String query="Select * from Student";
        	ResultSet rs = Stat.executeQuery( query );
		while(rs.next()){
			System.out.print(rs.getString(1));
			System.out.print("\t");
			System.out.print(rs.getString(2));
			System.out.print("\t");
			System.out.print(rs.getInt(3));
			System.out.print("\t");
			System.out.print(rs.getString(4));
			System.out.print("\t");
			System.out.print(rs.getString(5));
			System.out.print("\t");
			System.out.print(rs.getInt(6));
			System.out.print("\t");
			System.out.println("");
		}
	}
	
	public void Update(){
		String query="Select * from Student";
 	        ResultSet rs = Stat.executeQuery( query );
    
    	        while(rs.next()){
			String N=rs.getString(1);
			String D=rs.getString(2);
			String ND = D.substring(0,1)+'I'+'T'+D.substring(3,3)+'1'+'9'+D.substring(6);
            		degree="BS-IT";

            		String query2 = "UPDATE Student set RollNumber = '"+ND+"',Degree = '"+degree+"'where Name = '"+N+"';";
            		int rs2 = Stat.executeUpdate( query2 );

            		if(rs2 > 0){
                		System.out.println("Updated Successfully.");
            		}
            		else{
                		System.out.println("No Updation.");
            		}   
		}
		String NG="Male";
		String ON="Nihal";
		String query1="UPDATE Student set Gender = '"+NG+"' where Name = '"+ON+"';";
		int rs3 = Stat.executeUpdate( query1 );
		if(rs3>0)
			System.out.println(ON+"'s Gender changed from Female to Male");
		else
			System.out.println("Nothing Changed.");
		
	}
	
	public void DBInfo(){
		DatabaseMetaData DBMD = Con.getMetaData();
		String DBName = DBMD.getDatabaseProductName();
		String DBVer = DBMD.getDatabaseProductVersion();
		String DBDriver = DBMD.getDriverName();
		boolean IsRO = DBMD.isReadOnly();
		System.out.println("DB Name : " + DBName);
		System.out.println("DB Version : " + DBVer);
		System.out.println("DB Driver : " + DBDriver);
		System.out.println("Is DB Read-Only : " + IsRO);
	}

	public static void main(String[] args){
		String D="BCSF16A532";
		String ND = D.substring(0, 1)+'I'+'T'+D.substring(3,3)+'1'+'9'+D.substring(6);
		System.out.println(D+"\t"+ND);

/*		PrintAll();
		Update();
		DBInfo();
*/
	}
}

