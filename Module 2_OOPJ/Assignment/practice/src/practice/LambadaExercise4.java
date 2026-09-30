package practice;
import java.util.*;
import java.util.function.Supplier;
public class LambadaExercise4 {

	public static void main(String[] args) {
		Supplier<Integer> rn =()->{
			Random r =new Random();
			return 100 + r.nextInt(900);
		};
		System.out.println("Random 3-digit Number: " + rn.get());

	}

}
