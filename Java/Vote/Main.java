package Java.Vote;

import java.util.*;

class UnderageException extends Exception {
    public UnderageException(String message) {
        super(message);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.print("Enter your age: ");
            int age = sc.nextInt();
            if (age < 18) {
                throw new UnderageException("You must be at least 18 years old to register.");
            }
            System.out.println("Registration successful! You are eligible to vote.");
        } catch (UnderageException e) {
            System.out.println("Registration failed: " + e.getMessage());
        } catch (InputMismatchException e) {
            System.out.println("Dhang se input de: " + e.getMessage());
        }
        finally {
            sc.close();
        }
    }
}
