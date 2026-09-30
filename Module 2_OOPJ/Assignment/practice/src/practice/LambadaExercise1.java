package practice;
import java.util.*;
public class LambadaExercise1 {

	public static void main(String[] args) {
		List<String> list= Arrays.asList("Rahul", "Sanket","Shivam","Om");
		Comparator<String> c =(c1,c2) -> c1.compareTo(c2);
		list.sort(c);
		System.out.println("sorted array" +list);
	}

}
