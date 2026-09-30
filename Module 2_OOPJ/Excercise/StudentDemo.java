// Question 1 (Set 2): Student Class

class Student {
    String name;
    int roll_no;
    String phone_no;
    String address;

    public Student() {}

    public Student(String name, int roll_no, String phone_no, String address) {
        this.name = name;
        this.roll_no = roll_no;
        this.phone_no = phone_no;
        this.address = address;
    }

    public void printDetails() {
        System.out.println("Name: " + name);
        System.out.println("Roll No: " + roll_no);
        if (phone_no != null) System.out.println("Phone No: " + phone_no);
        if (address != null) System.out.println("Address: " + address);
    }
}

public class StudentDemo {
    public static void main(String[] args) {
        System.out.println("=== Part (a) ===");
        Student s1 = new Student();
        s1.name = "John";
        s1.roll_no = 2;
        s1.printDetails();

        System.out.println("\n=== Part (b) ===");
        Student sam = new Student("Sam", 1, "9876543210", "64C WallsStreat");
        Student john = new Student("John", 2, "9123456780", "26B WallsStreat");

        System.out.println("--- Sam's Details ---");
        sam.printDetails();

        System.out.println("\n--- John's Details ---");
        john.printDetails();
    }
}
