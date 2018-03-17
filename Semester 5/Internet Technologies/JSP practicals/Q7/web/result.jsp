<%-- 
    Document   : result
    Created on : Nov 3, 2016, 5:26:08 PM
    Author     : surbhi
--%>

<%@taglib prefix="t" uri="WEB-INF/tlds/Q7tags.tld" %>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>substring</title>
    </head>
    <body>
        <t:substring string="${param.string}" start="${param.start}" end="${param.end}" />
    </body>
</html>
