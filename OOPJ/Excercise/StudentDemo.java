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
        System.out.println("Name: " + name + ", Roll No: " + roll_no);
        if (phone_no != null) System.out.println("Phone: " + phone_no + ", Address: " + address);
    }
}

public class StudentDemo {
    public static void main(String[] args) {
        // Part (a): Assign roll_no=2 and name="John"
        Student s1 = new Student();
        s1.name = "John";
        s1.roll_no = 2;
        System.out.println("--- Student 1 ---");
        s1.printDetails();

        // Part (b): Assign and print details for Sam and John
        System.out.println("\n--- Students Sam & John ---");
        Student sam = new Student("Sam", 1, "9876543210", "64C Wall Street");
        Student john = new Student("John", 2, "9123456780", "26B Wall Street");

        sam.printDetails();
        john.printDetails();
    }
}
