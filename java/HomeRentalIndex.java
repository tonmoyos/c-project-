import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class HomeRentalIndex extends JFrame {
    public HomeRentalIndex() {
        setTitle("Find Your Home for Rent");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Background Panel
        JLabel background = new JLabel(new ImageIcon("home_background.jpg"));
        background.setLayout(new GridBagLayout());
        setContentPane(background);

        // UI Components
        JLabel emailLabel = new JLabel("Email:");
        JTextField emailField = new JTextField(15);
        JLabel passwordLabel = new JLabel("Password:");
        JPasswordField passwordField = new JPasswordField(15);
        JButton loginButton = new JButton("Login");
        JButton registerButton = new JButton("Register");
        JButton exitButton = new JButton("Exit");

        // Panel for fields
        JPanel panel = new JPanel();
        panel.setOpaque(false);
        panel.setLayout(new GridLayout(4, 2, 10, 10));
        panel.add(emailLabel);
        panel.add(emailField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        panel.add(loginButton);
        panel.add(registerButton);
        panel.add(exitButton);
        
        background.add(panel);

        // Button Actions
        loginButton.addActionListener(e -> JOptionPane.showMessageDialog(this, "Login Clicked"));
        registerButton.addActionListener(e -> JOptionPane.showMessageDialog(this, "Registration Clicked"));
        exitButton.addActionListener(e -> System.exit(0));
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new HomeRentalIndex().setVisible(true));
    }
}
