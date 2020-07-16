<%@ page language = "java" import = "java.sql.Statement,java.sql.ResultSet,java.sql.Connection,java.sql.DriverManager" %>
<%

try{
    Class.forName("com.mysql.jdbc.Driver");
    String url = "jdbc:mysql://127.0.0.1/project";
    Connection con=DriverManager.getConnection(url, "root", "root");

	String Cnic = (String)session.getAttribute("cnicno");

	System.out.println(Cnic);

	System.out.println("select * from cars where id='"+request.getParameter("id")+"'");
	Statement stmt = con.createStatement();
	ResultSet res = stmt.executeQuery("select * from cars where id='"+request.getParameter("id")+"'");
	String Cmp="";
	String Nm = "";
	String Col = "";
	String Mod="";
	if(res.next()){
		Nm= res.getString("Name");
		Col= res.getString("Color");
		Mod= res.getString("Model");
		Cmp= res.getString("Company");
	}

	System.out.println("Insert into Booked(CNIC, Company, Name, Color, Model) VALUES ('"+Cnic+"','"+Cmp+"','"+Nm+"','"+Col+"','"+Mod+"')");

	stmt.executeUpdate("Insert into Booked(CNIC, Company, Name, Color, Model) VALUES ('"+Cnic+"','"+Cmp+"','"+Nm+"','"+Col+"','"+Mod+"')");
	System.out.println("Bam Bam");
	response.sendRedirect("View.jsp");
}
catch(Exception e){System.out.println("Exception");}
%>
