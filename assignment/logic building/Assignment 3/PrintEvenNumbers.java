public class PrintEvenNumbers {

    // Method to print even numbers from 1 to 50
    public static void printEvenNumbers() {

        int number = 1;

        while (number <= 50) {

            if (number % 2 == 0) {
                System.out.print(number + " ");
            }

            number++;
        }
    }

    public static void main(String[] args) {

        printEvenNumbers();
    }
}
