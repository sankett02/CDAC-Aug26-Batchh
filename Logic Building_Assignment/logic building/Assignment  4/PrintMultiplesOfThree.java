import java.util.Scanner;

public class PrintMultiplesOfThree {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        for (int i = 3; i <= n; i = i + 3) {
            System.out.print(i + " ");
        }

        sc.close();
    }
}