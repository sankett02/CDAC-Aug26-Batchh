public class Question3 {

    public static void moveZeros(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return;
        }

        int count = 0;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                arr[count] = arr[i];
                count++;
            }
        }

        while (count < arr.length) {
            arr[count] = 0;
            count++;
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
        System.out.println("=== Question 3: Move All Zeros to the End ===");

        System.out.println("\nTest Case 1 (Example 1):");
        int[] input1 = {0, 5, 0, 3, 8, 0, 2};
        System.out.print("Before: ");
        printArray(input1);
        moveZeros(input1);
        System.out.print("After:  ");
        printArray(input1);

        System.out.println("\nTest Case 2 (Example 2):");
        int[] input2 = {4, 0, 5, 0, 2, 7};
        System.out.print("Before: ");
        printArray(input2);
        moveZeros(input2);
        System.out.print("After:  ");
        printArray(input2);

        System.out.println("\nTest Case 3 (No Zeros):");
        int[] input3 = {1, 2, 3, 4, 5};
        System.out.print("Before: ");
        printArray(input3);
        moveZeros(input3);
        System.out.print("After:  ");
        printArray(input3);

        System.out.println("\nTest Case 4 (All Zeros):");
        int[] input4 = {0, 0, 0, 0};
        System.out.print("Before: ");
        printArray(input4);
        moveZeros(input4);
        System.out.print("After:  ");
        printArray(input4);

        System.out.println("\nTest Case 5 (Zeros Already At End):");
        int[] input5 = {9, 8, 7, 0, 0};
        System.out.print("Before: ");
        printArray(input5);
        moveZeros(input5);
        System.out.print("After:  ");
        printArray(input5);
    }
}
