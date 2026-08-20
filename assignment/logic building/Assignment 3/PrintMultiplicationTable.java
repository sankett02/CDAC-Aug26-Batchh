import java.util.Scanner;

public class PrintMultiplicationTable {

    // Method to print multiplication table
    public static void printMultiplicationTable(int number) {

        for (int i = 1; i <= 10; i++) {
            System.out.println(number + " x " + i + " = " + (number * i));
        }
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        // Call the method
        printMultiplicationTable(number);

        scanner.close();
    }
}


