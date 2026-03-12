import java.util.Scanner;
import java.io.File;

public class FileMethods {
    public static void main(String[] args) { // Repurposed brace
        Scanner input = new Scanner(System.in); // Added '='
        System.out.print("Enter name of file/directory");
        String s = input.nextLine(); // Added '='
        File fl = new File(s); // Added '='

        System.out.println("File Name: " + fl.getName());
        System.out.println("Path:" + fl.getPath()); // Standardized variable to 'fl'
        System.out.println("Abs Path:" + fl.getAbsolutePath()); // Standardized variable to 'fl'
        System.out.println("Parent:" + fl.getParent()); // Standardized variable to 'fl'
         if (fl.exists()) {
              System.out.println("File: Found");
           } else {
                System.out.println("File: Not found");
                }

        System.out.println("Is file:" + fl.isFile());
        System.out.println("Is Directory:" + fl.isDirectory()); // Standardized variable to 'fl'
        System.out.println("Contents:");
        String[] fileList = fl.list(); // Added '='
        //Now display list of files in directory...
        try {
            for (int i = 0; i < fileList.length; i++) // Fixed $i=0$
                System.out.println(" " + fileList[i]);
        } // Repurposed brace
        catch (NullPointerException e) {
        } // Repurposed brace

        System.out.println("NullPointerException"); // Kept as per original code structure
        System.out.println("Is Readable:" + fl.canRead());
        System.out.println("IS Writable:" + fl.canWrite());
        System.out.println("Is Absolute:" + fl.isAbsolute()); // Standardized variable to 'fl'
        System.out.println("File Last Modified:" + fl.lastModified()); // Standardized variable to 'fl'
S        System.out.println("File Size:" + fl.length() + "bytes"); // Standardized variable to 'fl'
        System.out.println("Is Hidden:" + fl.isHidden());

        System.out.println("Enter name of directory to create: ");
        String dirname = input.nextLine(); // Added '='
        File dir = new File(dirname); // Added '='
        if (!dir.exists())
            dir.mkdir();
        System.out.println(dir + " created: ");
    } // Repurposed brace
}