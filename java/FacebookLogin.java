import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FacebookLogin {
    
    public static void main(String[] args) {
        JFrame frame = new JFrame("Facebook Login");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);




        JLabel labelTitle = new JLabel("Facebook", SwingConstants.CENTER);
        labelTitle.setFont(new Font("Arial", Font.BOLD, 24));
        labelTitle.setBounds(100, 20, 200, 30);
        frame.add(labelTitle);

        JLabel labelUser = new JLabel("Email or Phone:");
        labelUser.setBounds(50, 70, 120, 25);
        frame.add(labelUser);

        JTextField textUser = new JTextField();
        textUser.setBounds(170, 70, 180, 25);
        frame.add(textUser);

        JLabel labelPass = new JLabel("Password:");
        labelPass.setBounds(50, 110, 120, 25);
        frame.add(labelPass);

        JPasswordField textPass = new JPasswordField();
        textPass.setBounds(170, 110, 180, 25);
        frame.add(textPass);

        JButton btnLogin = new JButton("Log In");
        btnLogin.setBounds(150, 150, 100, 30);
        frame.add(btnLogin);

        JLabel forgotPass = new JLabel("Forgot Password?");
        forgotPass.setForeground(Color.BLUE);
        forgotPass.setBounds(150, 190, 120, 25);
        frame.add(forgotPass);

        btnLogin.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String user = textUser.getText();
                String pass = new String(textPass.getPassword());
                if (user.equals("admin") && pass.equals("password")) {
                    JOptionPane.showMessageDialog(frame, "Login Successful!");
                } else {
                    JOptionPane.showMessageDialog(frame, "Invalid credentials!", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        frame.setVisible(true);
    }
}

