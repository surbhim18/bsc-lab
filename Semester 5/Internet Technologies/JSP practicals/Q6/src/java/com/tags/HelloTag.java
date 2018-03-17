package com.tags;

import java.io.IOException;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

/**
 *
 * @author surbhi
 */
public class HelloTag extends SimpleTagSupport {

    private String name;

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public void doTag() throws JspException, IOException {

        JspWriter out = getJspContext().getOut();
        if (name != null) {
            out.println("Hello " + name + "<br>");
        }

    }

}
