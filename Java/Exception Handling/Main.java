import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("=== Exception Handling Demo ===\n");
        
        // First try-catch block: Handle ArithmeticException (Division by zero)
        System.out.println("1. Division Operation:");
        try {
            System.out.print("Enter the numerator: ");
            int numerator = scanner.nextInt();
            System.out.print("Enter the denominator: ");
            int denominator = scanner.nextInt();
            
            int result = numerator / denominator;
            System.out.println("Result: " + numerator + " / " + denominator + " = " + result);
            
        } catch (ArithmeticException e) {
            System.out.println("ERROR: Division by zero is not allowed!");
            System.out.println("Exception Details: " + e.getMessage());
        }
        
        System.out.println("\n" + "=".repeat(40) + "\n");
        
        // Second try-catch block: Handle ArrayIndexOutOfBoundsException
        System.out.println("2. Array Access Operation:");
        try {
            // Create an array with some elements
            int[] numbers = {10, 20, 30, 40, 50};
            System.out.println("Array elements: ");
            for (int i = 0; i < numbers.length; i++) {
                System.out.println("Index " + i + ": " + numbers[i]);
            }
            
            System.out.print("\nEnter array index to access (0-" + (numbers.length - 1) + "): ");
            int index = scanner.nextInt();
            
            int value = numbers[index];
            System.out.println("Value at index " + index + ": " + value);
            
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ERROR: Array index is out of bounds!");
            System.out.println("Exception Details: " + e.getMessage());
        }
        
        System.out.println("\n" + "=".repeat(40) + "\n");
        // Third try-catch block: Handle NumberFormatException (Bonus)
        System.out.println("3. String to Integer Conversion:");
        try {
            System.out.print("Enter a number as string: ");
            scanner.nextLine(); // consume newline
            String numberString = scanner.nextLine();
            
            int parsedNumber = Integer.parseInt(numberString);
            System.out.println("Successfully parsed: " + parsedNumber);
            System.out.println("Square of the number: " + (parsedNumber * parsedNumber));
            
        } catch (NumberFormatException e) {
            System.out.println("ERROR: Invalid number format!");
            System.out.println("Exception Details: " + e.getMessage());
        }
        
        System.out.println("\n" + "=".repeat(40) + "\n");
        
        // Demonstrating multiple exceptions in one try-catch with multiple catch blocks
        System.out.println("4. Multiple Exception Handling in One Block:");
        try {
            System.out.print("Enter a number for complex operations: ");
            String input = scanner.nextLine();
            
            // This could throw NumberFormatException
            int number = Integer.parseInt(input);
            
            // This could throw ArithmeticException
            int divisionResult = 100 / number;
            
            // This could throw ArrayIndexOutOfBoundsException
            int[] testArray = {1, 2, 3};
            int arrayValue = testArray[number];
            
            System.out.println("All operations successful!");
            System.out.println("Division result: " + divisionResult);
            System.out.println("Array value: " + arrayValue);
            
        } catch (NumberFormatException e) {
            System.out.println("ERROR: Invalid number format in complex operation!");
            System.out.println("Details: " + e.getMessage());
        } catch (ArithmeticException e) {
            System.out.println("ERROR: Division by zero in complex operation!");
            System.out.println("Details: " + e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ERROR: Array index out of bounds in complex operation!");
            System.out.println("Details: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("ERROR: Unexpected exception occurred!");
            System.out.println("Details: " + e.getMessage());
        }
        
        System.out.println("\nProgram completed successfully!");
        scanner.close();
    }
}
