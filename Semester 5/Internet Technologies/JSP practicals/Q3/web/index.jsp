<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
    <head>
        <title>User Info Entry Form</title>
    </head>
    <body>
        <form action="index.jsp" method="GET">
            <input type="hidden" name="submitted" value="true">
            <table>
                <c:if test="${param.submitted && empty param.userName}">
                    <tr>
                        <td></td>
                        <td colspan="2"><font color="red">Please enter your name.</font></td>
                        <td></td>
                    </tr>
                </c:if>
                <tr>
                    <td>Name:</td>
                    <td><input type="text" name="userName" value="<c:out value="${param.userName}" />"></td>
                </tr>
                <c:if test="${param.submitted && empty param.birthDate}">
                    <tr>
                        <td></td>
                        <td colspan="2"><font color="red">Please enter your birth date.</font></td>
                        <td></td>
                    </tr>
                </c:if>
                <tr>
                    <td>Birth Date:</td>
                    <td><input type="text" name="birthDate" value="<c:out value="${param.birthDate}" />"></td>
                    <td>(Use format yyyy-mm-dd)</td>
                </tr>
                <c:if test="${param.submitted && empty param.emailAddr}">
                    <tr>
                        <td></td>
                        <td colspan="2"><font color="red">Please enter your email address.</font></td>
                        <td></td>
                    </tr>
                </c:if>
                <tr>
                    <td>Email Address:</td>
                    <td><input type="text" name="emailAddr" value="<c:out value="${param.emailAddr}" />"></td>
                    <td>(Use format name@company.com)</td>
                </tr>
                <c:if test="${param.submitted && param.gender!= 'm' && param.gender != 'f' }">
                    <tr>
                        <td></td>
                        <td colspan="2"><font color="red">Please select a valid gender.</font></td>
                        <td></td>
                    </tr>
                </c:if>
                <tr>
                    <td>Gender:</td>
                    <td>
                        <c:choose>
                            <c:when test="${param.gender ==  'f'}">
                                <input type="radio" name="gender" value="m"> Male<br>
                                <input type="radio" name="gender" value="f" checked> Female
                            </c:when>
                            <c:otherwise>
                                <input type="radio" name="gender" value="m" checked> Male<br>
                                <input type="radio" name="gender" value="f"> Female
                            </c:otherwise>
                        </c:choose>
                    </td>
                </tr>
                <c:if test="${param.submitted && (param.luckyNumber<1 || param.luckyNumber>100)}">
                    <tr>
                        <td></td>
                        <td colspan="2"><font color="red">Please enter a valid lucky number.</font></td>
                        <td></td>
                    </tr>
                </c:if>                
                <tr>
                    <td>Lucky Number:</td>
                    <td><input type="text" name="luckyNumber" value="<c:out value="${param.luckyNumber}" />"></td>
                    <td>(A number between 1 and 100)</td>
                </tr>
                <c:forEach items="${paramValues.food}" var="current">
                    <c:choose>
                        <c:when test="${current == 'z'}">
                            <c:set var="pizzaSelected" value="true" />
                        </c:when>                        
                        <c:when test="${current == 'p'}">
                            <c:set var="pastaSelected" value="true" />
                        </c:when>                        
                        <c:when test="${current == 'c'}">
                            <c:set var="chineseSelected" value="true" />
                        </c:when>
                        <c:otherwise>
                            <c:set var="invalidSelection" value="true" />
                        </c:otherwise>
                    </c:choose>                    
                </c:forEach>
                <c:if test="${invalidSelection}">
                    <tr>
                        <td></td>
                        <td colspan="2"><font color="red">Please select valid favorite foods.</font></td>
                        <td></td>
                    </tr>
                </c:if>     
                <tr>
                    <td>Favorite Foods:</td>
                    <td>
                        <input type="checkbox" name="food" value="z" ${pizzaSelected ? 'checked' : ''}>Pizza<br>
                        <input type="checkbox" name="food" value="p" ${pastaSelected ? 'checked' : ''}>Pasta<br>
                        <input type="checkbox" name="food" value="c" ${chineseSelected ? 'checked' : ''}>Chinese 
                    </td>
                </tr>
                <tr>
                    <td colspan=3><input type="submit" value="Submit Data"></td>
                </tr> 
            </table>
        </form>        
    </body>    
</html>