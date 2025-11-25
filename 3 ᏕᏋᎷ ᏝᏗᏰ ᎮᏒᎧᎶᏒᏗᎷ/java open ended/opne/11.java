//Interfaces
//11. Drawable Interface

interface Drawable {
    void draw();
}

class Circle implements Drawable {
    @Override
    public void draw() {
        System.out.println("Drawing a circle ○");
    }
}

class Rectangle implements Drawable {
    @Override
    public void draw() {
        System.out.println("Drawing a rectangle □");
    }
}

class Text implements Drawable {
    private String content;
    
    public Text(String content) {
        this.content = content;
    }
    
    @Override
    public void draw() {
        System.out.println("Drawing text: " + content);
    }
}

public class Main {
    public static void main(String[] args) {
        Drawable[] drawables = {
            new Circle(),
            new Rectangle(),
            new Text("Hello World")
        };
        
        for (Drawable d : drawables) {
            d.draw();
        }
    }
}