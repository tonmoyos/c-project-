import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RegistrationPage extends JFrame {
    public RegistrationPage() {
        setTitle("User Registration");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        
        // Main panel
        JPanel mainPanel = new JPanel(new BorderLayout());
        
        // Panel for input fields
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 2, 10, 10));
        
        // Labels and fields
        JLabel emailLabel = new JLabel("Email:");
        JTextField emailField = new JTextField(15);
        
        JLabel nameLabel = new JLabel("Name:");
        JTextField nameField = new JTextField(15);
        
        JLabel nidLabel = new JLabel("NID Number:");
        JTextField nidField = new JTextField(15);
        
        JLabel phoneLabel = new JLabel("Phone Number:");
        JTextField phoneField = new JTextField(15);
        
        JLabel passwordLabel = new JLabel("Password:");
        JPasswordField passwordField = new JPasswordField(15);
        
        // Add components to panel
        panel.add(emailLabel);
        panel.add(emailField);
        panel.add(nameLabel);
        panel.add(nameField);
        panel.add(nidLabel);
        panel.add(nidField);
        panel.add(phoneLabel);
        panel.add(phoneField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        
        // Button panel
        JPanel buttonPanel = new JPanel();
        JButton registerButton = new JButton("Register");
        JButton exitButton = new JButton("Exit");
        
        // Set small button size
        registerButton.setFont(new Font("Arial", Font.PLAIN, 12));
        exitButton.setFont(new Font("Arial", Font.PLAIN, 12));
        
        buttonPanel.add(registerButton);
        buttonPanel.add(exitButton);
        
        // Center buttons
        buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
        
        // Add panels to main panel
        mainPanel.add(panel, BorderLayout.CENTER);
        mainPanel.add(buttonPanel, BorderLayout.SOUTH);
        
        add(mainPanel);
        
        // Button Actions
        registerButton.addActionListener(e -> JOptionPane.showMessageDialog(this, "Registration Successful!"));
        exitButton.addActionListener(e -> System.exit(0));
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new RegistrationPage().setVisible(true));
    }
}
