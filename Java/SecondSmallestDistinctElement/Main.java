package Java.SecondSmallestDistinctElement;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> nums = new ArrayList<>();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            nums.add(sc.nextInt());
        }
        TreeSet<Integer> s = new TreeSet<>();
        for (int num : nums) {
            s.add(num);
        }

        ArrayList<Integer> temp = new ArrayList<>();
        for (int num : s) {
            temp.add(num);
        }
        Collections.sort(temp);
        if (temp.size() < 2)
            System.out.println(-1);
        else
            System.out.println(temp.get(1));
        sc.close();
    }
}
