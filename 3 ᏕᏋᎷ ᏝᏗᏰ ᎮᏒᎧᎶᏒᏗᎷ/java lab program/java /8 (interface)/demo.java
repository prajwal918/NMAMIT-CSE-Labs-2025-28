package interface2;
import java.util.Scanner;

class circle implements area 
{
    public double double_space_compute()
    {
        System.out.println("enter the radius ");
        Scanner sc=new Scanner(System.in);
        int r=sc.nextInt();
        
        double area1=pie*r*r;
        
        return area1;
    }
}

class rectangle implements area
{
    public double double_space_compute()
    {
        System.out.println("enter the length breadth");
        Scanner sc=new Scanner(System.in);
        int length=sc.nextInt();
        int breadth=sc.nextInt();
        double area1=length*breadth;
        
        return area1;
    }
}
 
public class demo 
{
    public static void main(String[] args)
    {
        area a1=new circle();
        System.out.println("area of the circle"+a1.double_space_compute());
        
        area a2=new rectangle();
        System.out.println("area of the rectangle is"+a2.double_space_compute());
    }
}