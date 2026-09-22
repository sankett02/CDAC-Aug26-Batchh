package practice;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class StreamExample {

	public static void main(String[] args) {
		
		List<Integer> numbers =Arrays.asList(10,12,23,44);
		numbers.stream()
				.filter(n->n>20)
				.forEach(System.out::println);

	}

}
