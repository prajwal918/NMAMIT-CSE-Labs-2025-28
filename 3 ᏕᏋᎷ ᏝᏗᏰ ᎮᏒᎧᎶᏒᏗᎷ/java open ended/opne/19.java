//ArrayList
//19. Student Names ArrayList


import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        // Create ArrayList
        ArrayList<String> students = new ArrayList<>();
        
        // Add elements
        students.add("Alice");
        students.add("Bob");
        students.add("Charlie");
        students.add("David");
        
        System.out.println("Initial list: " + students);
        
        // Add at specific position
        students.add(2, "Eve");
        System.out.println("After adding Eve at index 2: " + students);
        
        // Update element
        students.set(0, "Alicia");
        System.out.println("After updating index 0: " + students);
        
        // Remove element
        students.remove("Bob");
        System.out.println("After removing Bob: " + students);
        
        // Remove by index
        students.remove(1);
        System.out.println("After removing index 1: " + students);
        
        // Display all students
        System.out.println("\nAll students:");
        for (int i = 0; i < students.size(); i++) {
            System.out.println((i + 1) + ". " + students.get(i));
        }
        
        // Using enhanced for loop
        System.out.println("\nUsing enhanced for:");
        for (String student : students) {
            System.out.println("- " + student);
        }
        
        // Check if exists
        System.out.println("\nContains 'Charlie'? " + students.contains("Charlie"));
        
        // Size
        System.out.println("Total students: " + students.size());
        
        // Clear all
        students.clear();
        System.out.println("After clearing: " + students);
        System.out.println("Is empty? " + students.isEmpty());
    }
}