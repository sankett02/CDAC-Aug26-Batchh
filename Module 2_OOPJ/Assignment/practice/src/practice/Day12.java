package practice;
import java.util.*;

public class Day12 {

    public static void main(String[] args) {

        Map<Integer, String> map = new HashMap<>();

        map.put(101, "Shivam");
        map.put(102, "Shivam");

        // keys
        System.out.println("......keys......");

        for (Integer key : map.keySet()) {
            System.out.println("key " + key);
        }

        // values
        System.out.println("......values......");

        for (String val : map.values()) {
            System.out.println("value " + val);
        }

        // keys and values
        System.out.println("......keys and values......");

        for (Map.Entry<Integer, String> entry : map.entrySet()) {
            System.out.println("key " + entry.getKey() +
                               " value " + entry.getValue());
        }
    }
}