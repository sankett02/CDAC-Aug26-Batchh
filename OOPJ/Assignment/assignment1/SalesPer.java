package OOPJ.Assignment.assignment1;

public class SalesPer extends Employee {

    public SalesPer(String name, String address, int age,
                    boolean gender, double salary) {

        super(name, address, age, gender, salary);
    }

    @Override
    public void display() {

        System.out.println("\n----- Sales Person -----");

        super.display();
    }
}