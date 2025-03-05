import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class HomePage {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Home Page");
        frame.setSize(500, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        
        // Background Image
        JLabel background = new JLabel(new ImageIcon("building.jpg")); // Add your image file
        background.setBounds(0, 0, 500, 500);
        frame.setContentPane(background);
        
        // Panel to center buttons
        JPanel panel = new JPanel();
        panel.setBounds(150, 150, 200, 200);
        panel.setOpaque(false);
        panel.setLayout(new GridLayout(4, 1, 10, 10));
        
        // Buttons
        JButton emailButton = new JButton("Email");
        JButton passwordButton = new JButton("Password");
        JButton loginButton = new JButton("Login");
        JButton registerButton = new JButton("Register");
        
        panel.add(emailButton);
        panel.add(passwordButton);
        panel.add(loginButton);
        panel.add(registerButton);
        
        frame.add(panel);
        
        // Register Button Action
        registerButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new RegistrationPage();
            }
        });
        
        frame.setVisible(true);
    }
}

class RegistrationPage {
    RegistrationPage() {
        JFrame regFrame = new JFrame("Registration Page");
        regFrame.setSize(400, 300);
        regFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        regFrame.setLayout(new FlowLayout());
        
        JLabel label = new JLabel("Registration Page");
        regFrame.add(label);
        
        regFrame.setVisible(true);
    }
}