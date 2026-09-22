package practice;
import java.util.*;

public class Exercise12{
	public static void main(String[]args) {
		
		//first treeset banana
		TreeSet<String> set1 = new TreeSet<>();
		
		//Add data
		set1.add("Red");
		set1.add("Blue");
		
		//second treeset banana
		TreeSet<String> set2 = new TreeSet<>();
		
		
		//Add data 
		set2.add("green");
		set2.add("Green");
		
		//Add set1 in set2
		set2.addAll(set1);
		
		//print 
		System.out.println(set2);
	}
}
