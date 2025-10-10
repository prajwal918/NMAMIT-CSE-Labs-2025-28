package interface1;

class bank implements account
{
    int balance;
    
    public void deposit(int amt)
    {
        balance=balance+amt;
        System.out.println("balance after deposit  " +balance);
    }
    
    public void withdraw(int amt)
    {
        if(amt>balance)
        {
            System.out.println("invalid ammount  ");
            return;
        }
        balance=balance-amt;
        System.out.println("balance after withdraw  "+balance);
    }
    
    void display()
    {
        System.out.println("BALANCE"+balance);
    }
}

public class demo 
{
    public static void main(String[] args)
    {
        account c1=new bank();
        c1.deposit(100);
        c1.withdraw(1000);
        c1.deposit(5454545);
    }
}