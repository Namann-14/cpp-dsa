package Java.Interface;

@FunctionalInterface
interface A {
    void show();
}


@FunctionalInterface 
interface B {
    int add(int a, int b);
}

public class Main {
    public static void main(String[] args) {
        // Normal Method
        // A obj = new A() {
        //     public void show() {
        //         System.out.println("This is normal");
        //     }
        // };
        // obj.show();

        // Lambda Expression
        // A obj = () -> System.out.println("Lambda Expression");
        // obj.show();

        // Lambda Expression using return type
        B obj = (int a, int b) -> a + b;
        System.out.println(obj.add(4, 5));
    }
}
