// Multithreading
//13. Two Thread Creation Methods

// Method 1: Extending Thread class
class MyThread extends Thread {
    private String taskName;
    
    public MyThread(String taskName) {
        this.taskName = taskName;
    }
    
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(taskName + " - Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

// Method 2: Implementing Runnable interface
class MyRunnable implements Runnable {
    private String taskName;
    
    public MyRunnable(String taskName) {
        this.taskName = taskName;
    }
    
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(taskName + " - Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Using Thread class
        MyThread thread1 = new MyThread("Thread-1");
        thread1.start();
        
        // Using Runnable interface
        MyRunnable runnable = new MyRunnable("Runnable-1");
        Thread thread2 = new Thread(runnable);
        thread2.start();
    }
}