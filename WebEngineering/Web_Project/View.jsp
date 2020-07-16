<html>
<head>
<title>Information</title></head>
<%@ page language = "java" import = "java.sql.Statement,java.sql.ResultSet,java.sql.Connection,java.sql.DriverManager" %>
<body>
	<a href="logout.jsp"><button>log out</button></a>
<%

try{
    Class.forName("com.mysql.jdbc.Driver");
    String url = "jdbc:mysql://127.0.0.1/project";
    Connection con=DriverManager.getConnection(url, "root", "root");

	String Cnic = (String)session.getAttribute("cnicno");
	System.out.println(Cnic);
	Statement stmt = con.createStatement();
	if(Cnic.equals("admin")){
		ResultSet rs = stmt.executeQuery("select * from services");
%>
		
		<form action="Del.jsp" method="POST">
				Delete ID : <input type="text" name="del">
				<input type="submit" value="Save">
		</form>
		<table>
		<tr>
			<th>CNIC</th>
			<th>ID</th>
			<th>Service</th>
		</tr>
<%
		while(rs.next()) {
			String no= rs.getString("Cnic");
	 		int ID = rs.getInt("ID");
	 		String Serv = rs.getString("service");
%>			

			<tr>
			<td><%= no %></td>	
			<td><%= ID %></td>
			<td><%= Serv %></td>
			</tr>
<%
		}
		out.println("</table>");
		

	}
	else{
%>

		<table>
			<tr>
				<th>Name</th>
				<th>CNIC</th>
				<th>Car Name</th>
				<th>Car No</th>
			</tr>
		</table>

<%
		ResultSet res = stmt.executeQuery("select * from user where Cnic='"+Cnic+"'");
		System.out.println("select * from user where Cnic='"+Cnic+"'");
		String N = "";
		String C = "";
		String CN = "";
		String CNo = "";
		if(res.next()){
			N= res.getString("Name");
			C= res.getString("Cnic");
			CN=res.getString("CarName");
			CNo=res.getString("CarNo");
		}
%>
		<table>
			<tr>
				<td><%= N%></td>
				<td><%= C%></td>
				<td><%= CN%></td>
				<td><%= CNo%></td>
			</tr>
		</table>
		<form action="Add.jsp" method="POST">
			Add Service : <input type="text" name="add">
			<input type="submit" value="Save">
		</form>

		<table>
		<tr>
			<th>ID</th>
			<th>Service</th>
		</tr>

<%	
		ResultSet rs = stmt.executeQuery("select * from services where CNIC='"+Cnic+"'");
%>
		
<%
		while(rs.next()) {
	 		int ID = rs.getInt("ID");
	 		String Serv = rs.getString("service");
%>
			<tr>
			<td><%= ID %></td>
			<td><%= Serv %></td>
			</tr>
<%
		}
		out.println("</table>");
	}
%>

<%
stmt.close();
con.close();
}
catch(Exception e){System.out.println("Exception");}
%>

</table>
</body>
</html>