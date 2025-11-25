// 2. Default vs Parameterized Constructors

class Student {
    private String name;
    private int age;
    
    // Default constructor
    public Student() {
        this.name = "Not Assigned";
        this.age = 0;
        System.out.println("Default constructor called");
    }
    
    // Parameterized constructor
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
        System.out.println("Parameterized constructor called");
    }
    
    public void display() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student(); // Uses default
        Student s2 = new Student("Alice", 20); // Uses parameterized
        
        s1.display();
        s2.display();
    }
}