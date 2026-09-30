// Question 2: Member and PrimeMembers Class Hierarchy

import java.util.Scanner;

class Member {
    private String name;
    private int age;
    private String phoneNumber;
    private String address;
    private double salary;

    public Member(String name, int age, String phoneNumber, String address, double salary) {
        this.name = name;
        this.age = age;
        this.phoneNumber = phoneNumber;
        this.address = address;
        this.salary = salary;
    }

    // Accessors and Mutators
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public int getAge() { return age; }
    public void setAge(int age) { this.age = age; }

    public String getPhoneNumber() { return phoneNumber; }
    public void setPhoneNumber(String phoneNumber) { this.phoneNumber = phoneNumber; }

    public String getAddress() { return address; }
    public void setAddress(String address) { this.address = address; }

    public double getSalary() { return salary; }
    public void setSalary(double salary) { this.salary = salary; }

    public void printSalary() {
        System.out.println("Salary: $" + salary);
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Phone Number: " + phoneNumber);
        System.out.println("Address: " + address);
        printSalary();
    }
}

class PrimeMembers extends Member {
    private int joiningYear;
    private double joiningFees;
    private boolean isActive;

    public PrimeMembers(String name, int age, String phoneNumber, String address, double salary,
                        int joiningYear, double joiningFees, boolean isActive) {
        super(name, age, phoneNumber, address, salary);
        this.joiningYear = joiningYear;
        this.joiningFees = joiningFees;
        this.isActive = isActive;
    }

    // Accessors and Mutators
    public int getJoiningYear() { return joiningYear; }
    public void setJoiningYear(int joiningYear) { this.joiningYear = joiningYear; }

    public double getJoiningFees() { return joiningFees; }
    public void setJoiningFees(double joiningFees) { this.joiningFees = joiningFees; }

    public boolean isActive() { return isActive; }
    public void setActive(boolean active) { isActive = active; }

    @Override
    public void display() {
        super.display();
        System.out.println("Joining Year: " + joiningYear);
        System.out.println("Joining Fees: $" + joiningFees);
        System.out.println("Is Active: " + isActive);
    }
}

public class MemberDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("=== Enter Details for Member ===");
        System.out.print("Name: ");
        String name = sc.nextLine();
        System.out.print("Age: ");
        int age = Integer.parseInt(sc.nextLine());
        System.out.print("Phone Number: ");
        String phone = sc.nextLine();
        System.out.print("Address: ");
        String address = sc.nextLine();
        System.out.print("Salary: ");
        double salary = Double.parseDouble(sc.nextLine());

        Member member = new Member(name, age, phone, address, salary);
        System.out.println("\n--- Displaying Member Details ---");
        member.display();

        System.out.println("\n=== Enter Details for Prime Member ===");
        System.out.print("Name: ");
        String pName = sc.nextLine();
        System.out.print("Age: ");
        int pAge = Integer.parseInt(sc.nextLine());
        System.out.print("Phone Number: ");
        String pPhone = sc.nextLine();
        System.out.print("Address: ");
        String pAddress = sc.nextLine();
        System.out.print("Salary: ");
        double pSalary = Double.parseDouble(sc.nextLine());
        System.out.print("Joining Year: ");
        int jYear = Integer.parseInt(sc.nextLine());
        System.out.print("Joining Fees: ");
        double jFees = Double.parseDouble(sc.nextLine());
        System.out.print("Is Active (true/false): ");
        boolean active = Boolean.parseBoolean(sc.nextLine());

        PrimeMembers prime = new PrimeMembers(pName, pAge, pPhone, pAddress, pSalary, jYear, jFees, active);
        System.out.println("\n--- Displaying Prime Member Details ---");
        prime.display();

        sc.close();
    }
}
