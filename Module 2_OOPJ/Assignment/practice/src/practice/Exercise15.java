package practice;

import java.util.TreeSet;

public class Exercise15 {

	public static void main(String[] args) {
		TreeSet<Integer> set = new TreeSet<>();
		set.add(55);
		set.add(66);
		set.add(77);
		set.add(88);
		set.add(99);
		int given = 85;
		System.out.println("TreeSet :" + set);
		System.out.println("Grater than or equal to :" + given + " is " + set.ceiling(given));
	}
}
