import java.util.*;

class stringdemot {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Please enter your string: ");
        String str = input.nextLine(); 
        
        int upper = 0, number = 0; 
        int cnt[] = new int[5]; 

        for (int i = 0; i < str.length(); i++) { 
            char ch = str.charAt(i); 
            
            if (ch >= 'A' && ch <= 'Z') { 
                upper++;
            } else if (ch >= '0' && ch <= '9') { 
                number++; 
            }
            
            if (str.charAt(i) == 'a' || str.charAt(i) == 'A') {
                cnt[0]++; 
            } else if (str.charAt(i) == 'e' || str.charAt(i) == 'E') {
                cnt[1]++; 
            } else if (str.charAt(i) == 'i' || str.charAt(i) == 'I') {
                cnt[2]++; 
            } else if (str.charAt(i) == 'o' || str.charAt(i) == 'O') {
                cnt[3]++; 
            } else if (str.charAt(i) == 'u' || str.charAt(i) == 'U') {
                cnt[4]++; 
            }
        } 

        System.out.println(" Upper case letters: " + upper); 
        System.out.println("Number of digits: " + number); 
        System.out.println("Number of 'a': " + cnt[0]); 
        System.out.println("Number of 'e': " + cnt[1]); 
        System.out.println("Number of 'i': " + cnt[2]); 
        System.out.println("Number of 'o': " + cnt[3]); 
        System.out.println("Number of 'u': " + cnt[4]); 
    } 
}