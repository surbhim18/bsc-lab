package com.beans;

import javax.ejb.Stateless;

/**
 *
 * @author surbhi
 */
@Stateless
public class ChocoBean {

    private String texture;

    public String getTexture() {
       
        String msg;
        
        switch (texture) {
            case "chewy":
                msg = "You should try Five Star, Bar One.";
                break;
            case "crunchy":
                msg = "You should try Munch, KitKat.";
                break;
            default:
                msg = "Sorry, we can't help you.";
                break;
        }
        return msg;
        
    }

    public void setTexture(String texture) {
        this.texture = texture;
    }
    
}
