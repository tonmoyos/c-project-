import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Teacher {
    String name;
    String subject;
    String location;
    double rating;

    public Teacher(String name, String subject, String location, double rating) {
        this.name = name;
        this.subject = subject;
        this.location = location;
        this.rating = rating;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Subject: " + subject + ", Location: " + location + ", Rating: " + rating;
    }
}

public class FindTeacher {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Teacher> teachers = new ArrayList<>();
        
        teachers.add(new Teacher("John Doe", "Mathematics", "Dhaka", 4.8));
        teachers.add(new Teacher("Jane Smith", "Physics", "Dhaka", 4.7));
        teachers.add(new Teacher("Emily Johnson", "Chemistry", "Dhaka", 4.6));
        teachers.add(new Teacher("Michael Brown", "Biology", "Dhaka", 4.9));
        
        System.out.println("Enter subject you want to learn: ");
        String subject = scanner.nextLine();
        
        System.out.println("Enter your location: ");
        String location = scanner.nextLine();
        
        System.out.println("Available teachers:");
        boolean found = false;
        for (Teacher teacher : teachers) {
            if (teacher.subject.equalsIgnoreCase(subject) && teacher.location.equalsIgnoreCase(location)) {
                System.out.println(teacher);
                found = true;
            }
        }
        
        if (!found) {
            System.out.println("No teachers found for your criteria.");
        }
        
        scanner.close();
    }
}