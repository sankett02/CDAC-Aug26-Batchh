package practice;

import java.util.*;

//Key Class jisme Comparable implement hai
class EmployeeId implements Comparable<EmployeeId> {
 int id;

 EmployeeId(int id) {
     this.id = id;
 }

 @Override
 public int compareTo(EmployeeId o) {
     if (this.id == o.id) return 0;
     else if (this.id > o.id) return 1;
     else return -1;
 }

 @Override
 public String toString() {
     return "ID: " + id;
 }
}

public class TreeMapDemo {
 public static void main(String[] args) {
     // Step 1: TreeMap banana
     Map<EmployeeId, String> map = new TreeMap<>();

     // Step 2: Un-sorted kram me data daalna
     map.put(new EmployeeId(1004), "Zahid");
     map.put(new EmployeeId(1000), "Tushar");
     map.put(new EmployeeId(1002), "Pankaj");

     // Step 3: Entries print karna
     for (Map.Entry<EmployeeId, String> entry : map.entrySet()) {
         System.out.println(entry.getKey() + " -> " + entry.getValue());
     }
 }
}