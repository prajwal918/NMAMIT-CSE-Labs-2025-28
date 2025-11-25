// 20. Array vs ArrayList

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // Array - fixed size
        System.out.println("=== Array ===");
        String[] arrayNames = new String[3];
        arrayNames[0] = "Alice";
        arrayNames[1] = "Bob";
        arrayNames[2] = "Charlie";
        
        System.out.println("Array: " + Arrays.toString(arrayNames));
        System.out.println("Array length: " + arrayNames.length);
        
        // Cannot add more elements without creating new array
        // arrayNames[3] = "David"; // ERROR: ArrayIndexOutOfBoundsException
        
        // To add element, need to create new array
        String[] newArray = new String[4];
        System.arraycopy(arrayNames, 0, newArray, 0, arrayNames.length);
        newArray[3] = "David";
        System.out.println("New Array: " + Arrays.toString(newArray));
        
        // ArrayList - dynamic size
        System.out.println("\n=== ArrayList ===");
        ArrayList<String> listNames = new ArrayList<>();
        listNames.add("Alice");
        listNames.add("Bob");
        listNames.add("Charlie");
        
        System.out.println("ArrayList: " + listNames);
        System.out.println("ArrayList size: " + listNames.size());
        
        // Easy to add more elements
        listNames.add("David");
        listNames.add("Eve");
        System.out.println("After adding: " + listNames);
        
        // Easy to remove
        listNames.remove("Bob");
        System.out.println("After removing Bob: " + listNames);
        
        System.out.println("\n=== Performance ===");
        // Arrays are faster for fixed size data
        // ArrayLists are more flexible for dynamic data
    }
}