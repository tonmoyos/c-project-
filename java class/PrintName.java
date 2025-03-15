
import java.util.Scanner;

public class PrintName {
    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Ask for user input
        System.out.print("Enter your name: ");
        String name = scanner.nextLine();
        
        // Print the user's name
        System.out.println("Hello, " + name + "!");
        
        // Close the scanner
        scanner.close();
    }
}
