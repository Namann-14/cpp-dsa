package Java.Practice;

import java.util.*;

class Student implements Comparable<Student> {
    private int age;
    private int marks;

    Student(int a, int m) {
        this.age = a;
        this.marks = m;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getMarks() {
        return marks;
    }

    public void setMarks(int marks) {
        this.marks = marks;
    }

    @Override
    public int compareTo(Student b) {
        if (this.age != b.age) {
            return Integer.compare(this.age, b.age);
        } else {
            return Integer.compare(this.marks, b.marks);
        }
    }
    
    @Override
    public String toString() {
        return "Student{age=" + age + ", marks=" + marks + "}";
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList<Student> sd = new LinkedList<>();
        sd.add(new Student(20, 85));
        sd.add(new Student(18, 92));
        sd.add(new Student(20, 78));
        sd.add(new Student(19, 88));
        sd.add(new Student(18, 95));
        
        System.out.println("Before sorting:");
        for (Student student : sd) {
            System.out.print(student + " ");
        }
        System.out.println();

        Collections.sort(sd);

        System.out.println("\nAfter sorting (by age, then by marks):");
        for (Student student : sd) {
            System.out.print(student + " ");
        }
        System.out.println();


        // Find and display 2nd largest marks
        int secondLargestMarks = findSecondLargestMarks(sd);
        if (secondLargestMarks == -1) {
            System.out.println("\nNo 2nd largest marks exist");
        } else {
            System.out.println("\n2nd largest marks: " + secondLargestMarks);
        }
    }
    
    public static int findSecondLargestMarks(LinkedList<Student> students) {
        if (students.isEmpty()) {
            return -1;
        }
        // Create a set to store unique marks
        Set<Integer> uniqueMarks = new HashSet<>();
        for (Student student : students) {
            uniqueMarks.add(student.getMarks());
        }
        
        // If all marks are same or less than 2 unique marks, return -1
        if (uniqueMarks.size() < 2) {
            return -1;
        }
        
        // Convert to list and sort in descending order to find 2nd largest
        List<Integer> sortedMarks = new ArrayList<>(uniqueMarks);
        Collections.sort(sortedMarks, Collections.reverseOrder());
        
        // Return 2nd largest marks
        return sortedMarks.get(1);
    }
}