package practice;

import java.util.function.Predicate;

public class LambdaExercise7 {

    public static void main(String[] args) {

        Predicate<Integer> isPrime = n -> {

            if (n < 2) {
                return false;
            }

            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    return false;
                }
            }

            return true;
        };

        int number = 76584;

        if (isPrime.test(number)) {
            System.out.println(number + " is Prime");
        } else {
            System.out.println(number + " is not Prime");
        }
    }
}