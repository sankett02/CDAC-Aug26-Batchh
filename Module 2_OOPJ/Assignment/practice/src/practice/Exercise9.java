package practice;

import java.util.*;

public class Exercise9 {

	public static void main(String[] args) {

		ArrayList<String> list1 = new ArrayList<>();
		list1.add("Shviam Soni1");
		list1.add("Shviam Soni2");
		list1.add("Shviam Soni3");

		Collections.shuffle(list1);

		System.out.println("For List 1: " + list1);
	}

}
