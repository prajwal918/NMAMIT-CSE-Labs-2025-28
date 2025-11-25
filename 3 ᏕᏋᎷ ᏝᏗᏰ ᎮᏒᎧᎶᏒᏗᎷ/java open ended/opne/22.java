
// 22. Queue using LinkedList
import java.util.LinkedList;

class Queue {
    private LinkedList<Integer> list;
    
    public Queue() {
        list = new LinkedList<>();
    }
    
    // Enqueue - add to rear
    public void enqueue(int data) {
        list.addLast(data);
        System.out.println("Enqueued: " + data);
    }
    
    // Dequeue - remove from front
    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return -1;
        }
        int data = list.removeFirst();
        System.out.println("Dequeued: " + data);
        return data;
    }
    
    // Peek - view front element
    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return -1;
        }
        return list.getFirst();
    }
    
    // Check if empty
    public boolean isEmpty() {
        return list.isEmpty();
    }
    
    // Get size
    public int size() {
        return list.size();
    }
    
    // Display queue
    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
        } else {
            System.out.println("Queue (Front -> Rear): " + list);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Queue queue = new Queue();
        
        System.out.println("=== Queue Operations ===");
        
        // Enqueue elements
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.enqueue(50);
        
        System.out.println();
        queue.display();
        
        System.out.println("\nFront element: " + queue.peek());
        System.out.println("Queue size: " + queue.size());
        
        // Dequeue elements
        System.out.println();
        queue.dequeue();
        queue.dequeue();
        
        System.out.println();
        queue.display();
        
        // Add more elements
        System.out.println();
        queue.enqueue(60);
        queue.enqueue(70);
        
        System.out.println();
        queue.display();
        
        // Dequeue all
        System.out.println("\n=== Dequeuing all elements ===");
        while (!queue.isEmpty()) {
            queue.dequeue();
        }
        
        System.out.println();
        queue.display();
        
        // Try to dequeue from empty queue
        System.out.println();
        queue.dequeue();
    }
}