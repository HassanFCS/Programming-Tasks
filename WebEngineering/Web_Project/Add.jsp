<%@ page language = "java" import = "java.sql.Statement,java.sql.ResultSet,java.sql.Connection,java.sql.DriverManager" %>
<%

try{
    Class.forName("com.mysql.jdbc.Driver");
    String url = "jdbc:mysql://127.0.0.1/project";
    Connection con=DriverManager.getConnection(url, "root", "root");

	String Cnic = (String)session.getAttribute("cnicno");
	System.out.println(Cnic);
	Statement stmt = con.createStatement();
	stmt.executeUpdate("Insert into services(CNIC, Service) VALUES ('"+Cnic+"','"+request.getParameter("add")+"')");
	System.out.println("Bam Bam");
	response.sendRedirect("View.jsp");
}
catch(Exception e){System.out.println("Exception");}
%>
