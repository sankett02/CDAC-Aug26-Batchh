public class OddNumberSequencePattern {
    public static void main(String[] args) {

        for (int i = 1; i <= 5; i++) {

            for (int j = 1; j <= i; j++) {

                int odd = 2 * j - 1;

                System.out.print(odd);

                if (j < i) {
                    System.out.print("*");
                }
            }

            System.out.println();
        }
    }
}