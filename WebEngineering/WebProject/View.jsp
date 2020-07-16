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
		ResultSet rs = stmt.executeQuery("select * from cars");
%>
		
		<form action="Del.jsp" method="POST">
				Delete ID : <input type="text" name="del">
				<input type="submit" value="Delete">
		</form>
		<form action="Add.jsp" method="POST">
			Company : <input type="text" name="company">
			Name : <input type="text" name="name">
			Color : <input type="text" name="color">
			Model : <input type="text" name="model">
			<input type="submit" value="Add">
		</form>
		<table>
		<tr>
			<th>id</th>
			<th>Company</th>
			<th>Name</th>
			<th>Color</th>
			<th>Model</th>
		</tr>
<%
		while(rs.next()) {
			String company= rs.getString("Company");
	 		String name = rs.getString("Name");
	 		String color = rs.getString("Color");
	 		String model = rs.getString("Model");	
	 		int id = rs.getInt("id");

%>			

			<tr>
			<td><%= id %></td>	
			<td><%= company %></td>
			<td><%= name %></td>
			<td><%= color %></td>
			<td><%= model %></td>
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
			</tr>
		</table>

<%
		ResultSet res = stmt.executeQuery("select * from users where Cnic='"+Cnic+"'");
		System.out.println("select * from user where Cnic='"+Cnic+"'");
		String N = "";
		String C = "";
		if(res.next()){
			N= res.getString("Name");
			C= res.getString("Cnic");
		}
%>
		<table>
			<tr>
				<td><%= N%></td>
				<td><%= C%></td>
			</tr>
		</table>

		<table>
			<tr>
				<th>Company</th>
				<th>Name</th>
				<th>Color</th>
				<th>Model</th>
			</tr>
		
<%
		ResultSet rs = stmt.executeQuery("select * from Booked where Cnic='"+Cnic+"'");
		while(rs.next()) {
			String company= rs.getString("Company");
	 		String name = rs.getString("Name");
	 		String color = rs.getString("Color");
	 		String model = rs.getString("Model");
%>			
				<tr>
					<td><%= company %></td>
					<td><%= name %></td>
					<td><%= color %></td>
					<td><%= model %></td>
				</tr>
			
<%
		}
		out.println("</table>");
%>


		<form action="Book.jsp" method="POST">
			Enter Car id : <input type="text" name="id">
			<input type="submit" value="Book">
		</form>
		<table>
		<tr>
			<th>id</th>
			<th>Company</th>
			<th>Name</th>
			<th>Color</th>
			<th>Model</th>
		</tr>
<%
		ResultSet r = stmt.executeQuery("select * from cars");
		while(r.next()) {
			String company= r.getString("Company");
	 		String name = r.getString("Name");
	 		String color = r.getString("Color");
	 		String model = r.getString("Model");	
	 		int id = r.getInt("id");

%>			

			<tr>
			<td><%= id %></td>	
			<td><%= company %></td>
			<td><%= name %></td>
			<td><%= color %></td>
			<td><%= model %></td>
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