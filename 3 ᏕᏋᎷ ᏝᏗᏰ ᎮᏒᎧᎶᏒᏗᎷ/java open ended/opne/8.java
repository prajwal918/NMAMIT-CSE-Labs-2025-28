//8. Shape and Circle Dynamic Dispatch

abstract class Shape {
    public abstract void draw();
    public abstract double area();
}

class Circle extends Shape {
    private double radius;
    
    public Circle(double radius) {
        this.radius = radius;
    }
    
    @Override
    public void draw() {
        System.out.println("Drawing Circle");
    }
    
    @Override
    public double area() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    private double width, height;
    
    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }
    
    @Override
    public void draw() {
        System.out.println("Drawing Rectangle");
    }
    
    @Override
    public double area() {
        return width * height;
    }
}

class Triangle extends Shape {
    private double base, height;
    
    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }
    
    @Override
    public void draw() {
        System.out.println("Drawing Triangle");
    }
    
    @Override
    public double area() {
        return 0.5 * base * height;
    }
}

public class Main {
    public static void main(String[] args) {
        Shape[] shapes = {
            new Circle(5),
            new Rectangle(4, 6),
            new Triangle(3, 4)
        };
        
        for (Shape shape : shapes) {
            shape.draw();
            System.out.println("Area: " + shape.area());
            System.out.println();
        }
    }
}