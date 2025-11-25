// Swing Programming
//17. Swing GUI with Button

import javax.swing.*;
import java.awt.event.*;

public class SimpleGUI {
    public static void main(String[] args) {
        // Create frame
        JFrame frame = new JFrame("Interactive GUI");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        
        // Create button
        JButton button = new JButton("Click Me!");
        button.setBounds(100, 100, 200, 40);
        
        // Create label
        JLabel label = new JLabel("Press the button", SwingConstants.CENTER);
        label.setBounds(100, 50, 200, 30);
        
        // Counter for clicks
        final int[] clickCount = {0};
        
        // Add action listener
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                clickCount[0]++;
                label.setText("Clicked " + clickCount[0] + " times!");
                JOptionPane.showMessageDialog(frame, 
                    "Button clicked " + clickCount[0] + " times!");
            }
        });
        
        // Add mouse listener for different interactions
        button.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                button.setText("Hover!");
            }
            
            @Override
            public void mouseExited(MouseEvent e) {
                button.setText("Click Me!");
            }
        });
        
        frame.add(button);
        frame.add(label);
        frame.setVisible(true);
    }
}