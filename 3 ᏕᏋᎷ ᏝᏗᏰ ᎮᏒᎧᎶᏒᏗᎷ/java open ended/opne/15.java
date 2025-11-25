// Exception Handling
//15. Division by Zero with try-catch

public class Main {
    public static void main(String[] args) {
        int[] numerators = {10, 20, 30, 40};
        int[] denominators = {2, 0, 5, 0};
        
        for (int i = 0; i < numerators.length; i++) {
            try {
                int result = numerators[i] / denominators[i];
                System.out.println(numerators[i] + " / " + denominators[i] + " = " + result);
            } catch (ArithmeticException e) {
                System.out.println("Error: Cannot divide " + numerators[i] + " by zero");
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Error: Array index out of bounds");
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            } finally {
                System.out.println("Operation completed for index " + i);
            }
        }
    }
}