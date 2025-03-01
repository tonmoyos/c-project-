import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class FindPartnerName {
    public static void main(String[] args) {
        // Predefined list of names and their partners
        Map<String, String> partners = new HashMap<>();
        partners.put("Tonmoy", "Monisha");
        partners.put("tonmoy", "Monisha");
        partners.put("Monisha", "Tonmoy");
        partners.put("monisha", "Tonmoy");
        partners.put("Rony", "Monisha");
        partners.put("rony", "Monisha");
        partners.put("roni", "Monisha");
        partners.put("Roni", "Monisha");
        partners.put("Motu", "Monisha");
        partners.put("motu", "Monisha");
        partners.put("Moni", "Tonmoy");
        partners.put("moni", "Tonmoy");
        partners.put("Motki", "Tonmoy");
        partners.put("motki", "Tonmoy");
        partners.put("Moti", "Tonmoy");
        partners.put("moti", "Tonmoy");


        
        // Taking user input
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = scanner.nextLine().trim();
        
        // Checking if the name exists in the predefined list
        if (partners.containsKey(name)) {
            System.out.println("Your partner's name is: " + partners.get(name));
        } else {
            System.out.println("Sorry, no partner found for the given name.");
        }
        
        scanner.close();
    }
}
