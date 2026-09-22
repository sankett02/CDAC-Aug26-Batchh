package practice;
import java.util.*;

public class Exercise14 {
    public static void main(String[] args) {

        // Step 1: TreeSet banana
        TreeSet<Integer> set = new TreeSet<>();

        // Step 2: Data add karna
        set.add(10);
        set.add(20);
        set.add(30);
        set.add(40);

        // Step 3: First element get karna
        System.out.println("First: " + set.first());

        // Step 4: Last element get karna
        System.out.println("Last: " + set.last());
    }
}
