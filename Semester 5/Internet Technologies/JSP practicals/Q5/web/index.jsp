<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<html>
    <head>
        <title>Form</title>
    </head>
    <body>
        <form action="index.jsp" method="GET">
            <input type="hidden" name="submitted" value="true">
            <table>
                <c:if test="${param.submitted && empty param.word}">
                    <tr>
                        <td></td>
                        <td colspan="2"><font color="red">Please enter a word.</font></td>
                        <td></td>
                    </tr>
                </c:if>
                <tr>
                    <td>Enter word:</td>
                    <td><input type="text" name="word" value="<c:out value="${param.word}" />"></td>
                </tr>
                <c:if test="${param.submitted && fn:contains(param.gender,'odd') && fn:contains(param.gender,'even') }">
                    <tr>
                        <td></td>
                        <td colspan="2"><font color="red">Please select a valid option.</font></td>
                        <td></td>
                    </tr>
                </c:if>
                <tr>
                    <td>Choose:</td>
                    <td>
                        <c:choose>
                            <c:when test="${fn:contains(param.type,'even')}">
                                <input type="radio" name="type" value="even" checked>Even<br>
                                <input type="radio" name="type" value="odd" >Odd
                            </c:when>
                            <c:otherwise>
                                <input type="radio" name="type" value="even">Even<br>
                                <input type="radio" name="type" value="odd" checked>Odd                            
                            </c:otherwise>
                        </c:choose>
                    </td>
                </tr>
                <tr>
                    <td colspan=2><input type="submit" value="Submit"></td>
                </tr> 
            </table>
        </form>        

        <%!
            int i, len;
            String word;
            char c;
            boolean flag;

        %>
        <c:choose>
            <c:when test="${fn:contains(param.type,'even')}">
                <%
                    flag=true;
                    word = request.getParameter("word");
                    len = word.length();
                    for (i = 1; i < len; i += 2) {
                        c = word.charAt(i);
                        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                            flag = false;
                            break;
                        }
                    }
                %>
            </c:when>
            <c:when test="${fn:contains(param.type,'odd')}">
                <%
                    flag=true;
                    word = request.getParameter("word");
                    len = word.length();
                    for (i = 0; i < len; i += 2) {
                        c = word.charAt(i);
                        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                            flag = false;
                            break;
                        }
                    }
                %>
            </c:when>
        </c:choose>
        <%
            if (("true").equals(request.getParameter("submitted"))) {
                if (flag) {
                    out.print("You win");
                } else {
                    out.print("You lose");
                }
            }
        %>
    </body>    
</html>