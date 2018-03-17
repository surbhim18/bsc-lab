<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@page import="java.lang.*"%>

<%
    int n = Integer.parseInt(request.getParameter("num"));
%>

<c:forEach var="i" begin="1" end="<%=n%>" >
    <c:forEach var="j" begin="1" end="${i}">
        <c:out value = "${j} " />
    </c:forEach>
    <br>
</c:forEach>

