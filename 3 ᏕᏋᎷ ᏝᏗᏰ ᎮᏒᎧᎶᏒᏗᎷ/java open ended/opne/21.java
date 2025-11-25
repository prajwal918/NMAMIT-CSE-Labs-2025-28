// LinkedList
//21. LinkedList Operations

import java.util.LinkedList;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        // Create LinkedList
        LinkedList<Integer> numbers = new LinkedList<>();
        
        // Add elements
        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        numbers.add(40);
        
        // Add at first and last
        numbers.addFirst(5);
        numbers.addLast(50);
        
        System.out.println("LinkedList: " + numbers);
        
        // Traverse
        System.out.println("\nTraversing:");
        for (Integer num : numbers) {
            System.out.print(num + " ");
        }
        
        // Insert at position
        numbers.add(3, 25);
        System.out.println("\n\nAfter inserting 25 at index 3: " + numbers);
        
        // Remove operations
        numbers.removeFirst();
        numbers.removeLast();
        System.out.println("After removing first and last: " + numbers);
        
        // Comparison with ArrayList
        System.out.println("\n=== LinkedList vs ArrayList ===");
        
        LinkedList<Integer> linkedList = new LinkedList<>();
        ArrayList<Integer> arrayList = new ArrayList<>();
        
        // Insertion at beginning
        long startTime = System.nanoTime();
        for (int i = 0; i < 10000; i++) {
            linkedList.addFirst(i);
        }
        long linkedTime = System.nanoTime() - startTime;
        
        startTime = System.nanoTime();
        for (int i = 0; i < 10000; i++) {
            arrayList.add(0, i);
        }
        long arrayTime = System.nanoTime() - startTime;
        
        System.out.println("LinkedList insertion time: " + linkedTime + " ns");
        System.out.println("ArrayList insertion time: " + arrayTime + " ns");
        System.out.println("LinkedList is faster for insertions at beginning!");
    }
}