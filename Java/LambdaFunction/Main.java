package Java.LambdaFunction;

// Functional interface for adding two numbers
@FunctionalInterface
interface Calculator {
    int add(int a, int b);
}

public class Main {
    public static void main(String[] args) {
        // Using lambda expression to implement the functional interface
        Calculator calculator = (a, b) -> a + b;
        
        // Test with two integers
        int num1 = 15;
        int num2 = 25;
        
        // Calculate the result using the lambda expression
        int result = calculator.add(num1, num2);
        
        // Print the result
        System.out.println("Adding " + num1 + " and " + num2 + " = " + result);
        
        // Additional examples
        System.out.println("Adding 10 and 20 = " + calculator.add(10, 20));
        System.out.println("Adding 100 and 200 = " + calculator.add(100, 200));
    }
}
