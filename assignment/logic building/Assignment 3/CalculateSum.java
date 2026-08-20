import java.util.Scanner;

public class CalculateSum {

    // Method to calculate the sum from 1 to N
    public static int calculateSum(int n) {

        int sum = 0;

        for (int i = 1; i <= n; i++) {
            sum = sum + i;
        }

        return sum;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = scanner.nextInt();

        // Call the method
        int result = calculateSum(n);

        System.out.println("The sum of numbers from 1 to " + n + " is: " + result);

        scanner.close();
    }
}

