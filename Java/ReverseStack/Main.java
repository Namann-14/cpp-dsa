package Java.ReverseStack;

import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> s = new Stack<>();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            s.push(sc.nextInt());
        }
        Stack<Integer>rev = new Stack<>();
        while (!s.empty()) {
            rev.push(s.pop());
        }
        while (!rev.empty()) {
            System.out.println(rev.pop());
        }
        sc.close();
    }
}
