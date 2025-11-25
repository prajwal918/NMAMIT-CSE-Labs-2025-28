//Inheritance & super Keyword
//5. Animal and Dog with super

class Animal {
    public void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    public void sound() {
        super.sound(); // Call parent method
        System.out.println("Dog barks");
    }
    
    public void bothSounds() {
        super.sound(); // Parent's version
        this.sound();  // Current version
    }
}

public class Main {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.sound();
        System.out.println("---");
        dog.bothSounds();
    }
}