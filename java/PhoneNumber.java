import java.lang.*;
import java.util.Scanner;
public class PhoneNumber {
    public static void main(String[]arg)
    {
        System.out.println("Here is your phone numbers:");
        Scanner s1 = new Scanner(System.in);
        System.out.println("Enter your phone number:");
        int value1 = s1.nextInt();
        System.out.println("Here your phone number" + value1);
        s1.close();
        
    }
    
}
