<%@taglib prefix="t" uri="WEB-INF/tlds/tags.tld" %>

<html>
    <head>
        <title>JSP Q8</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <form action="index.jsp" method="get" >
            String:<input type="text" name="string"/> 
            
            <input type="submit" value=" Reverse String"/>
        </form> 
        
        <t:reverse input="${param.string}" />
        
    </body>
</html>


