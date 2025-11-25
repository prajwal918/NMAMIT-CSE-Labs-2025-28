//10. Why Can't Instantiate Abstract Class

abstract class PaymentMethod {
    public abstract void processPayment(double amount);
    
    public void printReceipt() {
        System.out.println("Payment processed successfully");
    }
}

class CreditCard extends PaymentMethod {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing credit card payment: $" + amount);
    }
}

class PayPal extends PaymentMethod {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing PayPal payment: $" + amount);
    }
}

public class Main {
    public static void main(String[] args) {
        // PaymentMethod pm = new PaymentMethod(); // ERROR! Cannot instantiate
        
        PaymentMethod pm1 = new CreditCard();
        PaymentMethod pm2 = new PayPal();
        
        pm1.processPayment(100.00);
        pm2.processPayment(50.00);
    }
}