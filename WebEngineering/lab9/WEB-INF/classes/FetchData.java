import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.*

public class FetchData extends HttpServlet{
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException{
		res.setContentType("text/html");
		PrintWriter out=res.getWriter();

		String Name=req.getParameter("nm");

		try{
			Class.forName("com.mysql.jdbc,Driver");

			String url = "jdbc:mysql://127.0.0.1/lab9";

			Connection con=DriverManager.getConnection(url, "root", "root");

			Statement st=con.createStatement();

			String query="Select * from lab9 where Name='"+Name+"'";

			ResultSet rs=st.executeQuery(query);

			if(rs.next()){
				Cookie c=new Cookie(name);
				c.setMaxAge(2*24*60*60);
				res.addCookie(c);
		
				RequestDispatcher rd=response.("/MainServlet");
				rd.forward(req, res);
			}
			else{
				response.sendRedirect("errorServlet.java");
			}

		}catch(Exception e){
			out.println(e);
		}
	}
}