//Example - Ticket Booking System:

import java.util.LinkedList;

class TicketQueue {
    private LinkedList<String> customers;
    private int ticketsAvailable;
    
    public TicketQueue(int tickets) {
        customers = new LinkedList<>();
        ticketsAvailable = tickets;
    }
    
    public void addCustomer(String name) {
        customers.addLast(name);
        System.out.println(name + " joined the queue. Position: " + customers.size());
    }
    
    public void processNextCustomer() {
        if (customers.isEmpty()) {
            System.out.println("No customers in queue!");
            return;
        }
        
        if (ticketsAvailable > 0) {
            String customer = customers.removeFirst();
            ticketsAvailable--;
            System.out.println("✓ " + customer + " got a ticket! Remaining tickets: " + ticketsAvailable);
        } else {
            String customer = customers.removeFirst();
            System.out.println("✗ " + customer + " - Sorry, tickets sold out!");
        }
    }
    
    public void showQueue() {
        System.out.println("\nCurrent Queue: " + customers);
        System.out.println("People waiting: " + customers.size());
        System.out.println("Tickets available: " + ticketsAvailable + "\n");
    }
}

public class TicketBooking {
    public static void main(String[] args) {
        TicketQueue queue = new TicketQueue(3);
        
        System.out.println("=== Concert Ticket Booking ===\n");
        
        queue.addCustomer("Alice");
        queue.addCustomer("Bob");
        queue.addCustomer("Charlie");
        queue.addCustomer("David");
        queue.addCustomer("Eve");
        
        queue.showQueue();
        
        System.out.println("Processing customers...\n");
        queue.processNextCustomer();
        queue.processNextCustomer();
        queue.processNextCustomer();
        queue.processNextCustomer();
        queue.processNextCustomer();
    }
}