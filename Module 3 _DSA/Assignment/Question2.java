public class Question2 {

    public static void findSecondLargest(int[] arr) {
        if (arr == null || arr.length < 2) {
            System.out.println("Array must contain at least 2 elements.");
            return;
        }

        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;

        for (int num : arr) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num != largest) {
                secondLargest = num;
            }
        }

        if (secondLargest == Integer.MIN_VALUE) {
            System.out.println("No distinct second largest element found.");
        } else {
            System.out.println("Second Largest = " + secondLargest);
        }
    }

    public static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + (i < arr.length - 1 ? ", " : ""));
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        System.out.println("=== Question 2: Find Second Largest Element ===");

        System.out.println("\nTest Case 1 (Standard Example with duplicate max):");
        int[] input1 = {12, 5, 8, 20, 15, 20, 7};
        System.out.print("Input Array: ");
        printArray(input1);
        findSecondLargest(input1);

        System.out.println("\nTest Case 2 (Distinct Elements):");
        int[] input2 = {10, 20, 30, 40, 50};
        System.out.print("Input Array: ");
        printArray(input2);
        findSecondLargest(input2);

        System.out.println("\nTest Case 3 (All Equal Elements):");
        int[] input3 = {15, 15, 15, 15};
        System.out.print("Input Array: ");
        printArray(input3);
        findSecondLargest(input3);

        System.out.println("\nTest Case 4 (Negative Numbers):");
        int[] input4 = {-10, -3, -5, -1, -3};
        System.out.print("Input Array: ");
        printArray(input4);
        findSecondLargest(input4);

        System.out.println("\nTest Case 5 (Single Element):");
        int[] input5 = {99};
        System.out.print("Input Array: ");
        printArray(input5);
        findSecondLargest(input5);
    }
}
