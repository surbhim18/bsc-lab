<%@page import="java.lang.*"%>

<%
    int n = Integer.parseInt(request.getParameter("num"));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            out.print(j+" ");
        }
        out.print("<br>");
    }
%>

