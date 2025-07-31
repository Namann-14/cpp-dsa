package Java.CustomCom;

import java.util.Scanner;
import java.util.Stack;

public class Main {
    private static Stack<Integer> stack = new Stack<>();
    private static Scanner scanner = new Scanner(System.in);
    
    public static void main(String[] args) {
        int choice;
        
        System.out.println("=== Stack Operations Menu ===");
        
        do {
            displayMenu();
            System.out.print("Enter your choice (1-5): ");
            choice = scanner.nextInt();
            
            switch (choice) {
                case 1:
                    pushElement();
                    break;
                case 2:
                    popElement();
                    break;
                case 3:
                    peekElement();
                    break;
                case 4:
                    displayStack();
                    break;
                case 5:
                    System.out.println("Exiting program. Thank you!");
                    break;
                default:
                    System.out.println("Invalid choice! Please enter a number between 1-5.");
            }
            
            if (choice != 5) {
                System.out.println("\nPress Enter to continue...");
                scanner.nextLine(); // consume newline
                scanner.nextLine(); // wait for user input
            }
            
        } while (choice != 5);
        
        scanner.close();
    }
    
    private static void displayMenu() {
        System.out.println("\n================================");
        System.out.println("Stack Operations:");
        System.out.println("1. Push an element onto the stack");
        System.out.println("2. Pop (remove) the top element");
        System.out.println("3. Peek (view) the top element");
        System.out.println("4. Display all elements");
        System.out.println("5. Exit");
        System.out.println("================================");
    }
    
    private static void pushElement() {
        System.out.print("Enter the element to push: ");
        int element = scanner.nextInt();
        stack.push(element);
        System.out.println("Element " + element + " pushed onto the stack successfully!");
        System.out.println("Current stack size: " + stack.size());
    }
    
    private static void popElement() {
        if (stack.isEmpty()) {
            System.out.println("Stack is empty! Cannot pop element.");
        } else {
            int poppedElement = stack.pop();
            System.out.println("Element " + poppedElement + " popped from the stack successfully!");
            System.out.println("Current stack size: " + stack.size());
        }
    }
    
    private static void peekElement() {
        if (stack.isEmpty()) {
            System.out.println("Stack is empty! No top element to peek.");
        } else {
            int topElement = stack.peek();
            System.out.println("Top element of the stack: " + topElement);
        }
    }
    
    private static void displayStack() {
        if (stack.isEmpty()) {
            System.out.println("Stack is empty!");
        } else {
            System.out.println("Stack elements (top to bottom):");
            // Display from top to bottom
            for (int i = stack.size() - 1; i >= 0; i--) {
                if (i == stack.size() - 1) {
                    System.out.println("[TOP] " + stack.get(i));
                } else {
                    System.out.println("      " + stack.get(i));
                }
            }
            System.out.println("Stack size: " + stack.size());
        }
    }
}
