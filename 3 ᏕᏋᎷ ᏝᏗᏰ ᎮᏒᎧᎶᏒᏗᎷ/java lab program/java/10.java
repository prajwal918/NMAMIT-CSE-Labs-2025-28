import java.util.Scanner;

class ValidateUSNException extends Exception {
    public ValidateUSNException(String msg) {
        super(msg);
    }
}

public class CustomExceptionDemo {
    private static void ValidateUSN(String usn) throws ValidateUSNException {
        int len = usn.length();
        if (len != 10)
            throw new ValidateUSNException("USN WITH INVALID LENGTH");

        boolean firstThree = usn.startsWith("4NM");
        if (firstThree == false)
            throw new ValidateUSNException("USN DOESNOT START WITH 4NM");

        String year = usn.substring(3, 5);
        int y = Integer.parseInt(year);
        if (y > 22)
            throw new ValidateUSNException("U WITH INVALID YEAR");

        String branch = usn.substring(5, 7);
        String[] barr = { "CS", "CV", "AI", "EE", "EC", "ME", "RE", "BT", "IS", "CC", "DS" };
        boolean branchval = false;
        for (String str : barr) {
            if (branch.equals(str)) {
                branchval = true;
            }
        }
        if (branchval == false)
            throw new ValidateUSNException("USN WITH INVALID BRANCH");
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner r = new Scanner(System.in);
        System.out.println("Enter your USN: ");
        String str = r.nextLine();
        try {
            ValidateUSN(str);
        } catch (ValidateUSNException ex) {
            System.out.println(ex.getMessage());
        }
        System.out.println("Validation Completed..");
    }
}