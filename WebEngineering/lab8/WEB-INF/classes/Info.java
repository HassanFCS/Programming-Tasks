import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.*;


public class Info extends HttpServlet {

  //Process the HTTP Get request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    
    PrintWriter out = response.getWriter();

    
    out.println("<html>");
    out.println("<head><title>Response</title></head>");
    out.println("<body bgcolor=\"#ffffff\">");

    try{
      Class.forName("com.mysql.jdbc.Driver");

      String url = "jdbc:mysql://127.0.0.1/mobileInfo";

      Connection con=DriverManager.getConnection(url,"root","root");

      Statement st=con.createStatement();
      
       String query="Select * from mobileOutlet";
       System.out.println(query);
     
       ResultSet rs = st.executeQuery( query );
     
       if(rs.next()){
        out.println("<table><tr><th>Company Name</th><th>Model</th><th>Price</th>");
        out.print("<tr><td>"+rs.getString("companyName")+"</td><td>"+rs.getString("model")+"</td><td>");
        out.print(rs.getInt("price"));
        out.println("</td></tr>");

  	    while(rs.next()){
            out.print("<tr><td>"+rs.getString("companyName")+"</td><td>"+rs.getString("model")+"</td><td>");
            out.print(rs.getInt("price"));
            out.println("</td></tr>");

        }

        out.println("</table>");
	  }
     
    else{
    	response.sendRedirect("/lab8/error.html");
    }


out.println("</body></html>");
           st.close();
           con.close();

    }catch(Exception e){

      out.println(e);
    }

  }

}