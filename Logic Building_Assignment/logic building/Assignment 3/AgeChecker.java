import java.util.Scanner;

public class AgeChecker {

    // Method to check the age category
    public static void checkAgeCategory(int age) {

        if (age < 18) {
            System.out.println("You are a minor.");
        } else if (age < 60) {
            System.out.println("You are an adult.");
        } else {
            System.out.println("You are a senior citizen.");
        }
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your age: ");
        int age = scanner.nextInt();

        // Pass the age to the method
        checkAgeCategory(age);

        scanner.close();
    }
}

