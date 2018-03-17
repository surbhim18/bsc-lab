package q7;

import java.io.*;

/**
 *
 * @author surbhi
 */
public class Q7 {

    /**
     * @param args the command line arguments, file names args[0]: file to be
     * copied from args[1]: file to be copied to
     */
    public static void main(String[] args) throws IOException {
        
        if(args.length!=2){
            System.out.print("Two arguments needed.");
            return;
        }
        

        String fromFile = args[0];
        String toFile = args[1];

        FileInputStream fin = null;
        FileOutputStream fout = null;

        try {
            fin = new FileInputStream(fromFile);
        } catch (FileNotFoundException ex) {
            System.out.println("Input file not found!");
            return;
        }

        try {
            fout = new FileOutputStream(toFile);
        } catch (FileNotFoundException ex) {
            System.out.println("File not found!");
            return;
        }/*catch(ArrayIndexOutOfBoundsException ex){
            System.out.println("Array index out of bounds!");
            return;
        }*/
        

        int i;
        try {
            do {
                i = fin.read();
                if (i != -1) {
                    fout.write(i);
                }
            } while (i != -1);
        } catch (IOException e) {
            System.out.println("Error");
            return;
        }
        
        fin.close();
        fout.close();
    
        System.out.println("File successfully copied!");
    }
}
