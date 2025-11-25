// 6. Inheritance for Code Reusability

class Vehicle {
    protected String brand;
    protected int year;
    
    public Vehicle(String brand, int year) {
        this.brand = brand;
        this.year = year;
    }
    
    public void displayInfo() {
        System.out.println("Brand: " + brand + ", Year: " + year);
    }
    
    public void start() {
        System.out.println("Vehicle is starting...");
    }
}

class Car extends Vehicle {
    private int doors;
    
    public Car(String brand, int year, int doors) {
        super(brand, year);
        this.doors = doors;
    }
    
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Doors: " + doors);
    }
}

class Motorcycle extends Vehicle {
    private boolean hasSidecar;
    
    public Motorcycle(String brand, int year, boolean hasSidecar) {
        super(brand, year);
        this.hasSidecar = hasSidecar;
    }
    
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Has Sidecar: " + hasSidecar);
    }
}

public class Main {
    public static void main(String[] args) {
        Car car = new Car("Toyota", 2023, 4);
        Motorcycle bike = new Motorcycle("Harley", 2022, false);
        
        car.displayInfo();
        car.start();
        System.out.println();
        bike.displayInfo();
        bike.start();
    }
}