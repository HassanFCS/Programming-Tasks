import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.*;


public class Add extends HttpServlet {

  //Process the HTTP Get request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    
    PrintWriter out = response.getWriter();

    String cname=request.getParameter("cname");
    String model=request.getParameter("model");
    String price=request.getParameter("price");
    
    out.println("<html>");
    out.println("<head><title>Response</title></head>");
    out.println("<body bgcolor=\"#ffffff\">");
    

    try{
      Class.forName("com.mysql.jdbc.Driver");

      String url = "jdbc:mysql://127.0.0.1/mobileInfo";

      Connection con=DriverManager.getConnection(url,"root","root");

      Statement st=con.createStatement();
      
       String query="INSERT INTO mobileOutlet(companyName,model,price) VALUES ('"+cname+"','"+model+"',"+price+")";
       System.out.println(query);
     
       int rs = st.executeUpdate( query );
     
       if(rs==1){

  	     out.println("Successfully Added");

	  }
     
    else{
    	response.sendRedirect("/lab8/home.html");
    }


out.println("</body></html>");
           st.close();
           con.close();

    }catch(Exception e){

      out.println(e);
    }

  }

}