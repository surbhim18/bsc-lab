package com.tags;

import java.io.IOException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.tagext.SimpleTagSupport;
/**
 *
 * @author surbhi
 */
public class Date extends SimpleTagSupport {

    @Override
    public void doTag() throws JspException, IOException {
        JspWriter out = getJspContext().getOut();
        
        java.util.Date date = new java.util.Date();
        String str= date.toString();
        out.print(str);
    }
    
}
