package com.tags;

import java.io.IOException;
import java.lang.Integer.*;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.tagext.JspFragment;
import javax.servlet.jsp.tagext.SimpleTagSupport;

/**
 *
 * @author surbhi
 */
public class SubstringTag extends SimpleTagSupport {

    private String string;
    private String start;
    private String end;

    public String getString() {
        return string;
    }

    public void setString(String string) {
        this.string = string;
    }

    public String getStart() {
        return start;
    }

    public void setStart(String start) {
        this.start = start;
    }

    public String getEnd() {
        return end;
    }

    public void setEnd(String end) {
        this.end = end;
    }     
    
    private String getSubstring()
    {
       String substring;
       int len = string.length();
       int s = Integer.parseInt(start);
       int e = Integer.parseInt(end);
       
       if(s<0 || e<0 || s>=len || e>=len)
       {
           substring = "Invalid start or end indices";
       }
       else if(s > e)
       {
           substring = "Start index should be less than end index.";
       }
       else
       {
           substring = string.substring(s, e+1);
       }            
       
       return substring;
    }
    
    @Override
    public void doTag() throws JspException, IOException {
        JspWriter out = getJspContext().getOut();
        
        out.println(getSubstring());
        
    }    
}
