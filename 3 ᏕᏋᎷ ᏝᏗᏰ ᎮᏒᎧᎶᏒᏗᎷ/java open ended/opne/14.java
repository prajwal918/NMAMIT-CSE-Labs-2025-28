// 14. start() vs run() Methods

class MyThread extends Thread {
    @Override
    public void run() {
        System.out.println("Thread is running: " + Thread.currentThread().getName());
        for (int i = 1; i <= 3; i++) {
            System.out.println(Thread.currentThread().getName() + " - " + i);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();
        
        System.out.println("Using start():");
        t1.start(); // Creates new thread and calls run()
        t2.start(); // Creates another new thread
        
        System.out.println("\nUsing run() - WRONG WAY:");
        MyThread t3 = new MyThread();
        t3.run(); // Just calls method - no new thread created!
    }
}