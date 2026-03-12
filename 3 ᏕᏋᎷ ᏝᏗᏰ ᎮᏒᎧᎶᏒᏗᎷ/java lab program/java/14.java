import java.util.*;
import java.io.*;

public class filedemo { // Corrected from filedemof
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Corrected from SC new
        try {
            System.out.println("Enter the content: "); // Corrected from System out.println
            String S = sc.nextLine(); // Corrected from $S=Sc$ Sc.nextLine )
            FileWriter f1 = new FileWriter("input.txt"); // Corrected from "input txt")
            f1.write(S); // Corrected from fI write(s)
            f1.close(); // Corrected from close();

            FileReader F1 = new FileReader("input.txt"); // Corrected from $FI=new$ File Reader
            FileWriter f2 = new FileWriter("output.txt"); // Corrected from " output txt")
            int ch;
            while ((ch = F1.read()) != -1) { // Corrected from ( ch=Fl.read())
                f2.write(ch); // Corrected from f2 write (ch)
            }
            F1.close(); // Corrected from FI close()
            f2.close();

            FileReader F2 = new FileReader("output.txt");
            char[] array = new char[100]; // Corrected from Chart]
            F2.read(array);
            System.out.println("File contents: "); // Corrected from printin
            System.out.println(array);
            F2.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage()); // Combined lines
        }
    }
}