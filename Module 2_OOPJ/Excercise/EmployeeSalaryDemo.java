// Question 6 (Set 2): Employee Salary Adjustments

import java.util.Scanner;

public class EmployeeSalaryDemo {

    static class Employee {
        private double salary;
        private int hoursPerDay;

        // 1 - 'getInfo()' takes salary and hours of work per day as parameters
        public void getInfo(double salary, int hoursPerDay) {
            this.salary = salary;
            this.hoursPerDay = hoursPerDay;
        }

        // 2 - 'addSal()' adds $10 to salary if it is less than $500
        public void addSal() {
            if (salary < 500) salary += 10;
        }

        // 3 - 'addWork()' adds $5 to salary if work hours per day > 6
        public void addWork() {
            if (hoursPerDay > 6) salary += 5;
        }

        public double getFinalSalary() {
            return salary;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter initial salary ($): ");
        double sal = sc.nextDouble();

        System.out.print("Enter work hours per day: ");
        int hours = sc.nextInt();

        Employee emp = new Employee();
        emp.getInfo(sal, hours);
        emp.addSal();
        emp.addWork();

        System.out.println("Final Salary: $" + emp.getFinalSalary());

        sc.close();
    }
}
