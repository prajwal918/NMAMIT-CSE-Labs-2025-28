//12. Multiple Inheritance with Interfaces

interface Flyable {
    void fly();
}

interface Swimmable {
    void swim();
}

class Duck implements Flyable, Swimmable {
    @Override
    public void fly() {
        System.out.println("Duck is flying");
    }
    
    @Override
    public void swim() {
        System.out.println("Duck is swimming");
    }
}

class Fish implements Swimmable {
    @Override
    public void swim() {
        System.out.println("Fish is swimming");
    }
}

class Bird implements Flyable {
    @Override
    public void fly() {
        System.out.println("Bird is flying");
    }
}

public class Main {
    public static void main(String[] args) {
        Duck duck = new Duck();
        duck.fly();
        duck.swim();
        
        Fish fish = new Fish();
        fish.swim();
        
        Bird bird = new Bird();
        bird.fly();
    }
}