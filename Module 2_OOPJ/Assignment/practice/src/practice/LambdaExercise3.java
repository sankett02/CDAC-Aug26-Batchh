package practice;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class LambdaExercise3 {
	public static void main(String[]args) {
		List<Integer> list = Arrays.asList(10,12,11,14,16,90);
//		Comparator<Integer> c =(n1,n2)->n1.compareTo(n2);
		
		int largest = Collections.min(list);
		
		System.out.println("Largest number: " + largest);
	}

}
