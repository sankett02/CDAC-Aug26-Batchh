package practice;

import java.util.*;

public class Exercise8 {

	public static void main(String[] args) {

		ArrayList<String> list1 = new ArrayList<>();
		list1.add("Shviam Soni1");
		list1.add("Shviam Soni2");
		list1.add("Shviam Soni3");

		ArrayList<String> list2 = new ArrayList<>();
		list2.add("");
		list2.add("");
		list2.add("");

		Collections.copy(list2, list1);

		System.out.println("For List 1: " + list1);
		System.out.println("For List 2: " + list2);
	}

}