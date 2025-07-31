package Java.HighestFrequency;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.Map;

public class Main {
    private static boolean isVowel(char ch) {
        switch (ch) {
            case 'a' : 
            case 'e' : 
            case 'i' : 
            case 'o' : 
            case 'u' : return true;
            default : return false;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        TreeMap<Character,Integer> mp = new TreeMap<>();
        for (char ch : s.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }
        ArrayList<Character>chs= new ArrayList<>();
        for (Map.Entry<Character, Integer> e : mp.entrySet()) {
            if (!isVowel(e.getKey())) {
                chs.add(e.getKey());
            }
        }
        for (char ch : chs) {
            System.out.print(ch + " ");
        }
        sc.close();
    }
}
