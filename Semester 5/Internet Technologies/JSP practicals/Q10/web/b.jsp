<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%-- 
    Document   : b
    Created on : Nov 3, 2016, 6:45:57 PM
    Author     : surbhi
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Page 2</title>
    </head>
    <body>
        Hello <c:out value="${var}" />,<br>
        You have ordered Product <c:out value="${param.product}" />
    </body>
</html>
