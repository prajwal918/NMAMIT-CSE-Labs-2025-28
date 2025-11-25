//Abstract Classes
//9. Abstract Shape Class

abstract class Shape {
    protected String color;
    
    public Shape(String color) {
        this.color = color;
    }
    
    // Abstract method - no implementation
    public abstract double area();
    
    // Concrete method
    public void displayColor() {
        System.out.println("Color: " + color);
    }
}

class Square extends Shape {
    private double side;
    
    public Square(String color, double side) {
        super(color);
        this.side = side;
    }
    
    @Override
    public double area() {
        return side * side;
    }
}

class Circle extends Shape {
    private double radius;
    
    public Circle(String color, double radius) {
        super(color);
        this.radius = radius;
    }
    
    @Override
    public double area() {
        return Math.PI * radius * radius;
    }
}

public class Main {
    public static void main(String[] args) {
        Shape square = new Square("Red", 5);
        Shape circle = new Circle("Blue", 3);
        
        square.displayColor();
        System.out.println("Area: " + square.area());
        
        circle.displayColor();
        System.out.println("Area: " + circle.area());
    }
}