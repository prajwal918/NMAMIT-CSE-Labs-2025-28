//4. Overloading display Method

class Display {
    public void display(int number) {
        System.out.println("Integer: " + number);
    }
    
    public void display(String text) {
        System.out.println("String: " + text);
    }
    
    public void display(int number, String text) {
        System.out.println("Number: " + number + ", Text: " + text);
    }
}

public class Main {
    public static void main(String[] args) {
        Display d = new Display();
        d.display(100);
        d.display("Hello World");
        d.display(42, "The Answer");
    }
}