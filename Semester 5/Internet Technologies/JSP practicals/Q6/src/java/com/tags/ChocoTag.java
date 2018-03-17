package com.tags;

import com.beans.ChocoBean;
import java.io.IOException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.tagext.JspFragment;
import javax.servlet.jsp.tagext.SimpleTagSupport;

/**
 *
 * @author surbhi
 */
public class ChocoTag extends SimpleTagSupport {

    private String texture;

    public String getTexture() {
        return texture;
    }

    public void setTexture(String texture) {
        this.texture = texture;
    }
    
    @Override
    public void doTag() throws JspException, IOException {
      
        JspWriter out = getJspContext().getOut();
        
        ChocoBean obj = new ChocoBean();
        obj.setTexture(texture);
        out.println(obj.getTexture());
    }
    
}
