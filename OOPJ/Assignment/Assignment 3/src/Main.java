import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

class Employee implements Serializable {

    private static final long serialVersionUID = 1L;

    private int id;
    private String name;
    private double salary;

    public Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "ID: " + id + ", Name: " + name + ", Salary: " + salary;
    }
}

public class Main {

    public static void main(String[] args) {

        String filePath = "C:\\Users\\sanke\\OneDrive\\Documents\\New folder\\employees.txt";

        // Create Employee array
        Employee[] empArray = {
            new Employee(101, "Amit", 45000.0),
            new Employee(102, "Pankaj", 60000.0),
            new Employee(103, "Rahul", 55000.0)
        };

        // Save employees
        saveEmployees(filePath, empArray);

        // Load employees
        loadEmployees(filePath);
    }

    // Save Employee array to file
    private static void saveEmployees(String filePath, Employee[] emps) {

        try (ObjectOutputStream oos =
                new ObjectOutputStream(new FileOutputStream(filePath))) {

            oos.writeObject(emps);

            System.out.println("Employee array successfully saved to file!");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Load Employee array from file
    private static void loadEmployees(String filePath) {

        try (ObjectInputStream ois =
                new ObjectInputStream(new FileInputStream(filePath))) {

            Employee[] emps = (Employee[]) ois.readObject();

            System.out.println("\n--- Loaded Employees from File ---");

            for (Employee e : emps) {
                System.out.println(e);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}