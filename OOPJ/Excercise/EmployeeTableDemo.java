public class EmployeeTableDemo {

    static class Employee {
        private String name;
        private int yearOfJoining;
        private String address;

        public Employee(String name, int yearOfJoining, String address) {
            this.name = name;
            this.yearOfJoining = yearOfJoining;
            this.address = address;
        }

        public void printRow() {
            System.out.printf("%-12s %-20d %-20s%n", name, yearOfJoining, address);
        }
    }

    public static void main(String[] args) {
        System.out.printf("%-12s %-20s %-20s%n", "Name", "Year of joining", "Address");
        new Employee("Robert", 1994, "64C- WallsStreat").printRow();
        new Employee("Sam", 2000, "68D- WallsStreat").printRow();
        new Employee("John", 1999, "26B- WallsStreat").printRow();
    }
}
