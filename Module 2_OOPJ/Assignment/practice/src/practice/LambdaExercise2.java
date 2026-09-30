package practice;
import java.util.*;
public class LambdaExercise2 {

	public static void main(String[] args) {
		List<Integer> list = Arrays.asList(10,12,11,14,16,9990);
//		Comparator<Integer> c =(n1,n2)->n1.compareTo(n2);
		
		int largest = Collections.max(list);
	     Collections.reverse(list);
		
		System.out.println("Largest number: " + largest);
		System.out.println("Reverse number: " +list);
		

	}
}


