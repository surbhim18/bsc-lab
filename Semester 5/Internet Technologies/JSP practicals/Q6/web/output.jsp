<%@taglib prefix="cu" uri="WEB-INF/tlds/custom.tld" %>

<html>
    <body>
        <cu:hello name="${param.name}"/>   
        
        <cu:choco texture="${param.texture}"/>
        
       <!-- \<jsp:useBean id="beanObj" class="com.beans.ChocoBean"> -->
       <!--     \<jsp:setProperty name="beanObj" property="texture" value="\${param.texture}" />
            \<jsp:getProperty name="beanObj" property="texture"/>
        \</jsp:useBean> -->

    </body>
</html>
