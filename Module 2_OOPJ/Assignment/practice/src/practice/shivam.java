package practice;

import java.util.Arrays;
import java.util.function.Supplier;
import java.util.Random;
import java.util.*;

//record Students(String name, int age) {	
//}

//interface Calculator{
//	int add(int x, int y);
//	
//	static void message() {
//		System.out.println("Calculator Interface");
//	}
//}

public class shivam {

	public static void main(String[] args) {
//		Students s = new Students("Shivam", 31);
//		System.out.println(s.name());
//		System.out.println(s.age());
//		List<String>names = Arrays.asList("Sanket","Om", "Shivam");
//		names.sort((a,b)-> a.compareTo(b));
//		
//		names.stream()
//				.filter(name->name.startsWith("A"))
//				.forEach(name->System.out.println(names));
//		
//		System.out.println(names);
		
//		Calculator c =(x,y) -> x + y;
//		System.out.println(c.add(10,20));
//		
//		Calculator.message();
		Supplier<Integer> s =() ->{
			Random r = new Random();
			return r.nextInt(100);
		};
		
		System.out.println("Random Number" + s.get());
	}

}

