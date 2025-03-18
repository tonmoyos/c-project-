import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

public class ReverseStopwatchApp {
    private JFrame frame;
    private JLabel timeLabel;
    private JButton startButton, pushButton, addButton, resetButton;
    private JTextField timeInput;
    private Timer timer;
    private int remainingTime = 60; // Default time in seconds
    private boolean isRunning = false;

    public ReverseStopwatchApp() {
        frame = new JFrame("Reverse Stopwatch");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(3, 1));

        timeLabel = new JLabel("01:00", SwingConstants.CENTER);
        timeLabel.setFont(new Font("Arial", Font.BOLD, 24));
        frame.add(timeLabel);

        JPanel buttonPanel = new JPanel(new FlowLayout());
        startButton = new JButton("Start");
        pushButton = new JButton("Pause");
        addButton = new JButton("Add");
        resetButton = new JButton("Reset");
        buttonPanel.add(startButton);
        buttonPanel.add(pushButton);
        buttonPanel.add(addButton);
        buttonPanel.add(resetButton);
        frame.add(buttonPanel);

        JPanel inputPanel = new JPanel(new FlowLayout());
        timeInput = new JTextField(5);
        inputPanel.add(new JLabel("Add Time (sec):"));
        inputPanel.add(timeInput);
        frame.add(inputPanel);

        timer = new Timer(1000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (remainingTime > 0) {
                    remainingTime--;
                    updateTimeLabel();
                } else {
                    timer.stop();
                    isRunning = false;
                    playSound();
                    JOptionPane.showMessageDialog(frame, "Time's up!", "Alert", JOptionPane.INFORMATION_MESSAGE);
                }
            }
        });

        startButton.addActionListener(e -> startStopwatch());
        pushButton.addActionListener(e -> pauseStopwatch());
        addButton.addActionListener(e -> addTime());
        resetButton.addActionListener(e -> resetStopwatch());

        frame.setVisible(true);
    }

    private void startStopwatch() {
        if (!isRunning) {
            timer.start();
            isRunning = true;
        }
    }

    private void pauseStopwatch() {
        if (isRunning) {
            timer.stop();
            isRunning = false;
        }
    }

    private void addTime() {
        try {
            int additionalTime = Integer.parseInt(timeInput.getText());
            if (additionalTime > 0) {
                remainingTime += additionalTime;
                updateTimeLabel();
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Please enter a valid number.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void resetStopwatch() {
        timer.stop();
        remainingTime = 60;
        isRunning = false;
        updateTimeLabel();
    }

    private void updateTimeLabel() {
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;
        timeLabel.setText(String.format("%02d:%02d", minutes, seconds));
    }

    private void playSound() {
        try {
            File soundFile = new File("alarm.wav"); // Place an alarm.wav file in the project folder
            if (soundFile.exists()) {
                Clip clip = AudioSystem.getClip();
                clip.open(AudioSystem.getAudioInputStream(soundFile));
                clip.start();
            }
        } catch (Exception ex) {
            System.out.println("Error playing sound: " + ex.getMessage());
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(ReverseStopwatchApp::new);
    }
}
