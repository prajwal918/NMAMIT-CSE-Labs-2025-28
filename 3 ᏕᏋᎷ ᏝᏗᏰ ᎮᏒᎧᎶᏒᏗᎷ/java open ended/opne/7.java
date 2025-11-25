// Dynamic Method Dispatch
//7. Superclass Reference to Subclass Object

class Employee {
    public void work() {
        System.out.println("Employee is working");
    }
    
    public void getSalary() {
        System.out.println("Employee gets salary");
    }
}

class Manager extends Employee {
    @Override
    public void work() {
        System.out.println("Manager is managing team");
    }
    
    @Override
    public void getSalary() {
        System.out.println("Manager gets higher salary + bonus");
    }
}

class Developer extends Employee {
    @Override
    public void work() {
        System.out.println("Developer is coding");
    }
}

public class Main {
    public static void main(String[] args) {
        Employee emp1 = new Manager();    // Superclass reference
        Employee emp2 = new Developer();  // Superclass reference
        
        emp1.work();      // Calls Manager's work() - runtime decision
        emp1.getSalary(); // Calls Manager's getSalary()
        
        emp2.work();      // Calls Developer's work()
        emp2.getSalary(); // Calls Employee's getSalary()
    }
}