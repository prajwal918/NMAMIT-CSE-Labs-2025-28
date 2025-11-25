//Constructors
//1. Book Class with Constructor

class Book {
    private String title;
    private String author;
    
    // Parameterized constructor
    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }
    
    // Constructor with only title (constructor overloading)
    public Book(String title) {
        this.title = title;
        this.author = "Unknown";
    }
    
    // Default constructor
    public Book() {
        this.title = "Untitled";
        this.author = "Unknown";
    }
    
    public void display() {
        System.out.println("Title: " + title + ", Author: " + author);
    }
}

public class Main {
    public static void main(String[] args) {
        Book book1 = new Book("1984", "George Orwell");
        Book book2 = new Book("To Kill a Mockingbird", "Harper Lee");
        Book book3 = new Book("The Great Gatsby");
        Book book4 = new Book();
        
        book1.display();
        book2.display();
        book3.display();
        book4.display();
    }
}