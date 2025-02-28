import java.lang.*;
import java.util.Scanner;
public class Number{
    public static void main(String []args)
    {
        System.out.println("This is your 1st number");
        Scanner s1 = new Scanner(System.in);
        System.out.println("Enter Your Numbers:");
        int value = s1.nextInt();
        System.out.println("This Your Full Numbers:"+ value);
        s1.close();
    }
}
