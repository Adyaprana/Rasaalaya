// Program 2: Read 5 student marks. Handle InvalidMarkException for out-of-range input.

import java.util.Scanner;

// Custom checked exception
class InvalidMarkException extends Exception {
    public InvalidMarkException(String message) {
        super(message);
    }
}

public class Program2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] marks = new int[5];

        System.out.println("Enter 5 marks (between 0 and 100):");
        for (int i = 0; i < 5; i++) {
            while (true) {
                try {
                    System.out.print("Enter mark for student " + (i + 1) + ": ");
                    int mark = scanner.nextInt();
                    if (mark < 0 || mark > 100) {
                        throw new InvalidMarkException("Invalid mark: " + mark + ". Mark must be between 0 and 100.");
                    }
                    marks[i] = mark;
                    break; // exit the while loop for valid mark
                } catch (InvalidMarkException e) {
                    System.out.println("Error: " + e.getMessage());
                } catch (Exception e) {
                    System.out.println("Error: Please enter a valid integer.");
                    scanner.next(); // consume invalid input
                }
            }
        }

        scanner.close();
        System.out.println("\nAll marks entered successfully:");
        for (int i = 0; i < 5; i++) {
            System.out.println("Student " + (i + 1) + ": " + marks[i]);
        }
    }
}
