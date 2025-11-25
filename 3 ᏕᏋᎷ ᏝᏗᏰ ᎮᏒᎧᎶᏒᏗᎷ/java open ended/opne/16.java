// 16. Custom Exception
// Custom Exception
class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

class Person {
    private String name;
    private int age;
    
    public Person(String name, int age) throws InvalidAgeException {
        this.name = name;
        if (age < 0 || age > 150) {
            throw new InvalidAgeException("Invalid age: " + age + ". Age must be between 0 and 150.");
        }
        this.age = age;
    }
    
    public void display() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

public class Main {
    public static void main(String[] args) {
        try {
            Person p1 = new Person("Alice", 25);
            p1.display();
            
            Person p2 = new Person("Bob", -5); // Will throw exception
            p2.display();
        } catch (InvalidAgeException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
        
        try {
            Person p3 = new Person("Charlie", 200); // Will throw exception
            p3.display();
        } catch (InvalidAgeException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}