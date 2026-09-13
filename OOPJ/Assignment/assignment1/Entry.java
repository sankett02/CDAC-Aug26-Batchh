package OOPJ.Assignment.assignment1;

import mylibrary.ConsoleInputProgram;

public class Entry {

    public static void main(String[] args) {

        Employee e1 =
            new Manager("Rahul", "Mumbai", 30, true, 50000);

        Employee e2 =
            new Engineer("Amit", "Pune", 25, true, 40000);

        Employee e3 =
            new SalesPer("Priya", "Thane", 28, false, 35000);

        e1.display();
        e2.display();
        e3.display();
    }
}
