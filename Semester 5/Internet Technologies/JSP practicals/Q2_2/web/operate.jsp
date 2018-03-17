<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<c:choose>
    <c:when test="${param.op == 'a'}">
        Sum is: <c:out value="${param.a + param.b}" ></c:out>
    </c:when>
    <c:when test="${param.op == 's'}">
        Difference is: <c:out value="${param.a - param.b}" ></c:out>
    </c:when>
    <c:when test="${param.op == 'm'}">
        Product is: <c:out value="${param.a * param.b}" ></c:out>
    </c:when>
</c:choose>