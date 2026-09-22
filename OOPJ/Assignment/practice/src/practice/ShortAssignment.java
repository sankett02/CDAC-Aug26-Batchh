package practice;

import java.util.ArrayList;

public class ShortAssignment {

	public static void main(String[] args) {
		
		ArrayList<String> obj = new ArrayList();
		
		obj.add("red");
		obj.add("green");
		obj.add("yellow");
		
		System.out.println(obj);
		
		System.out.println("=======================");
		
		obj.set(0, "Sanket");
		System.out.println(obj);
		
		System.out.println("=======================");
		
		System.out.println(obj.get(0));
		
		System.out.println("=======================");
		
		obj.set(1, "neon");
		System.out.println(obj);

		System.out.println("=======================");
		
		obj.remove(0);
		System.out.println(obj);
		
		System.out.println("=======================");
	}
}

