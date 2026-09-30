import java.util.Scanner;

public class SumOfTwoNumbers {

    // Method to calculate the sum of two numbers
    public static int sumOfTwoNumbers(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // Take input from the user
        System.out.print("Enter first number: ");
        int firstNumber = scanner.nextInt();

        System.out.print("Enter second number: ");
        int secondNumber = scanner.nextInt();

        // Call the method
        int sum = sumOfTwoNumbers(firstNumber, secondNumber);

        // Print the result
        System.out.println("The sum of " + firstNumber + " and "
                + secondNumber + " is " + sum);

        scanner.close();
    }
}
