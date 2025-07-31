package Java.Comparables;

import java.util.Collections;
import java.util.LinkedList;

class Account implements Comparable<Account> {
    private String name;
    private int balance;

    public Account(String name, int balance) {
        this.name = name;
        this.balance = balance;
    }

    @Override
    public int compareTo(Account b) {
        return Integer.compare(b.balance, this.balance);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getBalance() {
        return balance;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList<Account> list = new LinkedList<>();
        list.add(new Account("Hardik", 0));
        list.add(new Account("Hardik", 10));
        list.add(new Account("Naman", 100));
        list.add(new Account("Jatin", -1));

        // for (Account ac : list) {
        // System.out.println(ac.getName() + " " +ac.getBalance());
        // }

        Collections.sort(list);

        for (Account ac : list) {
            System.out.println(ac.getName().toUpperCase() + " " + ac.getBalance());
        }
    }
}
