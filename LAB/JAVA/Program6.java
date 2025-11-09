// Program 6: Input and Validate 20 Marks
import java.util.Scanner;

// Custom exception class for invalid marks
class WrongMarkException extends Exception {
    public WrongMarkException(String message) {
        super(message);
    }
}

public class Program6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] marks = new int[20];

        System.out.println("Enter 20 marks (between 0 and 100):");

        for (int i = 0; i < 20; i++) {
            while (true) {
                try {
                    System.out.print("Enter mark " + (i + 1) + ": ");
                    int mark = sc.nextInt();

                    // Validate mark
                    if (mark < 0 || mark > 100) {
                        throw new WrongMarkException(
                                "❌ Invalid mark: " + mark + " (Marks must be between 0 and 100)"
                        );
                    }

                    // If valid, store it and break out of the loop
                    marks[i] = mark;
                    break;

                } catch (WrongMarkException e) {
                    System.out.println(e.getMessage());
                } catch (Exception e) {
                    System.out.println("⚠️ Error: Please enter a valid integer.");
                    sc.nextLine(); // clear invalid input
                }
            }
        }

        // Display entered marks
        System.out.println("\n✅ All marks entered successfully:");
        for (int i = 0; i < marks.length; i++) {
            System.out.println("Mark " + (i + 1) + ": " + marks[i]);
        }

        sc.close();
    }
}
