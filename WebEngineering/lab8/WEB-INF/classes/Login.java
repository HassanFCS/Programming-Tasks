import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.*;


public class Login extends HttpServlet {

  //Process the HTTP Get request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    
    PrintWriter out = response.getWriter();

    String u_name=request.getParameter("uname");
    String u_pass=request.getParameter("pass");
    

    try{
      Class.forName("com.mysql.jdbc.Driver");

      String url = "jdbc:mysql://127.0.0.1/class_test";

      Connection con=DriverManager.getConnection(url,"root","root");

      Statement st=con.createStatement();
      
       String query="Select * from login where user_name='"+u_name+"' AND password='"+u_pass+"'";
       System.out.println(query);
     
       ResultSet rs = st.executeQuery( query );
     
       if(rs.next()){

  	     response.sendRedirect("/test/success.html");

	  }
     
    else{
    	response.sendRedirect("/test/login.html");
    }


out.println("</body></html>");
           st.close();
           con.close();

    }catch(Exception e){

      out.println(e);
    }

  }

}