<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%-- 
    Document   : a
    Created on : Nov 3, 2016, 6:45:51 PM
    Author     : surbhi
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Page 1</title>
    </head>
    <body>
        Hello <c:out value="${param.name}" /> <br><br>
        <form method="get" action="b.jsp">
            Which product would you like to buy? <br>
            Select product: <br>
            <input type="radio" name="product" value="A" checked> A <br>
            <input type="radio" name="product" value="B" > B <br>
            <input type="radio" name="product" value="C" > C <br>

            <br>
            <input type="submit" value="Next Page"/>
        </form>
        
        <c:set var="var" value="${param.name}" scope="session" />
        
    </body>
</html>
