<html>
<head>
<title>Information</title></head>

<%@ page language = "java" import = "java.sql.Statement,java.sql.ResultSet,java.sql.Connection,java.sql.DriverManager,javax.swing.*" %>
<body>



<%
try{
    Class.forName("com.mysql.jdbc.Driver");
    String url = "jdbc:mysql://127.0.0.1/project";
    Connection con=DriverManager.getConnection(url, "root", "root");

String CNIC = request.getParameter("cnic");
System.out.println("A : "+CNIC);
String Password = request.getParameter("password");

Statement stmt = con.createStatement();
ResultSet result = stmt.executeQuery("select * from user WHERE Cnic='"+CNIC+"' AND Password='"+Password+"'");

if(result.next())
{
	session.setAttribute("cnicno",CNIC);
	response.sendRedirect("View.jsp");
}
else
{
JOptionPane.showMessageDialog(null, "Invalid CNIC or Password.");
}


%>

<%
stmt.close();
con.close();
%>

<%
}
catch(Exception e){System.out.println("Exception");} %>

</body>
</html>