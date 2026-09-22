package practice;

import java.util.*;

class Student {
    String name;
    int age;

    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

// Comparator for sorting by age
class AgeComparator implements Comparator<Student> {

    @Override
    public int compare(Student s1, Student s2) {

        if (s1.age == s2.age)return 0;
        else if (s1.age > s2.age)return 1;
        else return -1;
    }
}

public class ComparatorDemo {

    public static void main(String[] args) {

        List<Student> list = new ArrayList<>();

        list.add(new Student("Pankaj", 25));
        list.add(new Student("Tushar", 20));
        list.add(new Student("Rahul", 22));

        // Sort using AgeComparator
        Collections.sort(list, new AgeComparator());

        // Print
        for (Student s : list) {
            System.out.println(s.name + " - Age: " + s.age);
        }
    }
}
