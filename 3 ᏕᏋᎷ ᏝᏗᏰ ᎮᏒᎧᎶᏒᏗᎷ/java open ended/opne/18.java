// 18. JFrame and JButton Roles

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ExtendedGUI {
    public static void main(String[] args) {
        // JFrame - main window container
        JFrame frame = new JFrame("Calculator GUI");
        frame.setSize(300, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());
        
        // Text field for display
        JTextField display = new JTextField();
        display.setEditable(false);
        display.setFont(new Font("Arial", Font.BOLD, 24));
        frame.add(display, BorderLayout.NORTH);
        
        // Panel for buttons
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 5, 5));
        
        // Add number buttons
        String[] buttons = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", "C", "=", "+"
        };
        
        for (String text : buttons) {
            JButton button = new JButton(text);
            button.setFont(new Font("Arial", Font.PLAIN, 18));
            
            button.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    String current = display.getText();
                    if (text.equals("C")) {
                        display.setText("");
                    } else if (text.equals("=")) {
                        // Simple evaluation (would need proper implementation)
                        display.setText(current + " = ?");
                    } else {
                        display.setText(current + text);
                    }
                }
            });
            
            buttonPanel.add(button);
        }
        
        frame.add(buttonPanel, BorderLayout.CENTER);
        frame.setVisible(true);
    }
}