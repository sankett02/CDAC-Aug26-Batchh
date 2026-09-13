package OOPJ.Assignment.assignment1;

import java.io.Serializable;

public class Employee implements Serializable {

    protected String name;
    protected String address;
    protected int age;
    protected boolean gender;
    protected double salary;

    public Employee(String name, String address, int age,
                    boolean gender, double salary) {

        this.name = name;
        this.address = address;
        this.age = age;
        this.gender = gender;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public int getAge() {
        return age;
    }

    public boolean getGender() {
        return gender;
    }

    public double getSalary() {
        return salary;
    }

    public void display() {

        System.out.println("Name    : " + name);
        System.out.println("Address : " + address);
        System.out.println("Age     : " + age);
        System.out.println("Gender  : " + (gender ? "Male" : "Female"));
        System.out.println("Salary  : " + salary);
    }
}