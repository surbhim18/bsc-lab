<!-- https://www.tutorialspoint.com/java/java_date_time.htm -->

<%@page import="java.util.*,java.lang.*,java.text.*"%>

<%!
    Date d= new Date();
    SimpleDateFormat ft = new SimpleDateFormat ("H");
%>

<%
    int hours = Integer.parseInt(ft.format(d));
    
    if(hours>=19)
        out.print("Good evening, user.");
    else if(hours>= 12)
        out.print("Good afternoon, user.");
    else
        out.print("Good morning, user.");    
%>