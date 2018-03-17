<%@page import="java.lang.*"%>

<%
    int a = Integer.parseInt(request.getParameter("a"));
    int b = Integer.parseInt(request.getParameter("b"));
    String op = request.getParameter("op");
    
    if(op.equals("addition"))
        out.print("Sum is: "+ (a+b));
    else if(op.equals("subtraction"))
        out.print("Difference is: " + (a-b));
    else if(op.equals("multiplication"))
        out.print("Product is: " + (a*b));
   
%>