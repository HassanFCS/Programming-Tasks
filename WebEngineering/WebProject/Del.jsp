<%@ page language = "java" import = "java.sql.Statement,java.sql.ResultSet,java.sql.Connection,java.sql.DriverManager" %>
<%

try{
    Class.forName("com.mysql.jdbc.Driver");
    String url = "jdbc:mysql://127.0.0.1/project";
    Connection con=DriverManager.getConnection(url, "root", "root");

	String Cnic = (String)session.getAttribute("cnicno");
	System.out.println(Cnic);
	Statement stmt = con.createStatement();
	System.out.println("delete from cars where ID='"+request.getParameter("del")+"'");
	
	stmt.executeUpdate("delete from cars where ID='"+request.getParameter("del")+"'");

	response.sendRedirect("View.jsp");
}
catch(Exception e){System.out.println("Exception");}
%>