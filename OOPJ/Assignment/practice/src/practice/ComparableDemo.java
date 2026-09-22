package practice;
import java.util.*;

class ComparableDemo1 implements Comparable<ComparableDemo1>{
	int rollNo;
	
	ComparableDemo1(int rollNo){
		this.rollNo=rollNo;
	}

	@Override
	public int compareTo(ComparableDemo1 o) {
		if(this.rollNo==o.rollNo)return 0;
		else if (this.rollNo>o.rollNo)return 1;
		else return -1;
	}
}
 public class ComparableDemo{
	 public static void main(String[]args) {
		 List<ComparableDemo1>list = new ArrayList<>();
		 list.add(new ComparableDemo1(103));
		 list.add(new ComparableDemo1(102));
		 list.add(new ComparableDemo1(101));
		 
		 Collections.sort(list);
		 
		 for(ComparableDemo1 sam : list) {
			System.out.println("RollNo" +sam.rollNo);
		 }
	 }
 }