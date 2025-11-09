import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Program3 extends JFrame implements ActionListener {

    JTextField nameField, ageField, contactField, fatherNameField, incomeField;
    JLabel nameLabel, ageLabel, contactLabel, fatherNameLabel, incomeLabel;
    JButton submitButton, cleanButton;

    public Program3() {
        // Input fields
        nameField = new JTextField(20);
        ageField = new JTextField(20);
        contactField = new JTextField(20);
        fatherNameField = new JTextField(20);
        incomeField = new JTextField(20);

        // Labels
        nameLabel = new JLabel("Name:");
        ageLabel = new JLabel("Age:");
        contactLabel = new JLabel("Contact:");
        fatherNameLabel = new JLabel("Father's Name:");
        incomeLabel = new JLabel("Annual Income:");

        // Buttons
        submitButton = new JButton("Submit");
        cleanButton = new JButton("Clean");

        // Layout
        setLayout(new GridLayout(6, 2, 10, 10));
        add(nameLabel); add(nameField);
        add(ageLabel); add(ageField);
        add(contactLabel); add(contactField);
        add(fatherNameLabel); add(fatherNameField);
        add(incomeLabel); add(incomeField);
        add(submitButton); add(cleanButton);

        submitButton.addActionListener(this);
        cleanButton.addActionListener(this);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == submitButton) {
            validateInputs();
        } else if (e.getSource() == cleanButton) {
            cleanFields();
        }
    }

    private void validateInputs() {
        String name = nameField.getText().trim();
        String age = ageField.getText().trim();
        String contact = contactField.getText().trim();
        String fatherName = fatherNameField.getText().trim();
        String income = incomeField.getText().trim();

        if (name.isEmpty() || age.isEmpty() || contact.isEmpty() || fatherName.isEmpty() || income.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Please fill in all fields.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        if (!name.matches("^[a-zA-Z\\s]+$")) {
            JOptionPane.showMessageDialog(this, "Name should contain only alphabets.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        if (!fatherName.matches("^[a-zA-Z\\s]+$")) {
            JOptionPane.showMessageDialog(this, "Father's Name should contain only alphabets.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        if (!age.matches("^(?:1?[0-9]{1,2})$")) {
            JOptionPane.showMessageDialog(this, "Age must be a valid number between 1 and 120.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        if (!contact.matches("^[0-9]{10}$")) {
            JOptionPane.showMessageDialog(this, "Contact number must be 10 digits.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        if (!income.matches("^\\d+(\\.\\d{1,2})?$")) {
            JOptionPane.showMessageDialog(this, "Income must be a valid number (e.g., 250000 or 250000.50).", "Validation Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        // Success pop-up
        JOptionPane.showMessageDialog(this,
                "Registration Successful!\n\n"
                        + "Name: " + name + "\n"
                        + "Age: " + age + "\n"
                        + "Contact: " + contact + "\n"
                        + "Father's Name: " + fatherName + "\n"
                        + "Annual Income: " + income,
                "Success", JOptionPane.INFORMATION_MESSAGE);
    }

    private void cleanFields() {
        nameField.setText("");
        ageField.setText("");
        contactField.setText("");
        fatherNameField.setText("");
        incomeField.setText("");
    }

    public static void main(String[] args) {
        Program3 f = new Program3();
        f.setTitle("Student Registration");
        f.setSize(600, 300);
        f.setLocationRelativeTo(null); // center window
        f.setVisible(true);
    }
}
