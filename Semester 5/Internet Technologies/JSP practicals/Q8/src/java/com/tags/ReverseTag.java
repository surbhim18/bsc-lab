package com.tags;

import java.io.IOException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.tagext.JspFragment;
import javax.servlet.jsp.tagext.SimpleTagSupport;

/**
 *
 * @author surbhi
 */
public class ReverseTag extends SimpleTagSupport {

    private String string;

    public String getString() {
        return string;
    }

    public void setString(String string) {
        this.string = string;
    }
    
    private String reverse(){
        
        String rev;
        
        StringBuilder str= new StringBuilder();
        str.append(string);
        str = str.reverse();
        
        rev= str.toString();
        return rev;        
    }
    
    @Override
    public void doTag() throws JspException, IOException {
        JspWriter out = getJspContext().getOut();
        
        out.print(reverse());
       
    }
    
}
