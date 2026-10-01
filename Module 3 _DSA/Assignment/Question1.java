public class Question1 {

    public static void findMaxMin(int[] arr) {
        if (arr == null || arr.length == 0) {
            System.out.println("Array is empty!");
            return;
        }

        int max = arr[0];
        int min = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        System.out.println("Maximum = " + max);
        System.out.println("Minimum = " + min);
    }

    public static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + (i < arr.length - 1 ? ", " : ""));
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        System.out.println("=== Question 1: Find Maximum and Minimum ===");

        System.out.println("\nTest Case 1 (Standard Input):");
        int[] input1 = {15, 8, 23, 4, 19, 7};
        System.out.print("Input Array: ");
        printArray(input1);
        findMaxMin(input1);

        System.out.println("\nTest Case 2 (Negative Numbers):");
        int[] input2 = {-10, -5, -2, -20, -1};
        System.out.print("Input Array: ");
        printArray(input2);
        findMaxMin(input2);

        System.out.println("\nTest Case 3 (Single Element):");
        int[] input3 = {42};
        System.out.print("Input Array: ");
        printArray(input3);
        findMaxMin(input3);

        System.out.println("\nTest Case 4 (All Equal Elements):");
        int[] input4 = {7, 7, 7, 7};
        System.out.print("Input Array: ");
        printArray(input4);
        findMaxMin(input4);
    }
}
