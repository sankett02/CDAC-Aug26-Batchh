package OOPJ.Assignment.assignment1;

public class Engineer extends Employee {

    public Engineer(String name, String address, int age,
                    boolean gender, double salary) {

        super(name, address, age, gender, salary);
    }

    @Override
    public void display() {

        System.out.println("\n----- Engineer -----");

        super.display();
    }
}