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


String Name = request.getParameter("name");
String CNIC = request.getParameter("cnic");
String Password = request.getParameter("password");


Statement stmt = con.createStatement();


ResultSet rs = stmt.executeQuery("select * from users WHERE Cnic='"+CNIC+"'");

if(rs.next()){
	JOptionPane.showMessageDialog(null, "Cnic already exist.!!");
	response.sendRedirect("Sign.html");
}
else{
	int result = stmt.executeUpdate("INSERT INTO users(Name, Cnic, Password)VALUES('"+Name+"','"+CNIC+"','"+Password+"')");
	JOptionPane.showMessageDialog(null, "Now You can login.!!");
	response.sendRedirect("log.html");
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