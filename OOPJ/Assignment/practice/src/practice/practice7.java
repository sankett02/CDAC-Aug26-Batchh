package practice;
import java.util.*;
public class practice7 {

	public static void main(String[] args) {
	  ArrayList<Integer>demo=new ArrayList<>();
	  
	  demo.add(90);
	  demo.add(20);
	  demo.add(40);
	  demo.add(30);
	  demo.add(50);
	  demo.add(80);
	  
	  Collections.sort(demo);
	  
	  System.out.println("sorted array" +demo);
	}

}
