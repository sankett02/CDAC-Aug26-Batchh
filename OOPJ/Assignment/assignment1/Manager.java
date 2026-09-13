package OOPJ.Assignment.assignment1;

public class Manager extends Employee {

    public Manager(String name, String address, int age,
                   boolean gender, double salary) {

        super(name, address, age, gender, salary);
    }

    @Override
    public void display() {

        System.out.println("\n----- Manager -----");

        super.display();
    }
}