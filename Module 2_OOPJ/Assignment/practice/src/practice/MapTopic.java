package practice;

//topic 1 - Map Key, Value aur Entry Iteration Methods
////
////English:
////Map iteration methods allow retrieving and processing stored keys, values, or key-value pairs using keySet() for all keys, values() for all values, and entrySet() for combined key-value entries.   
//
//// Keys iterate karne ke liye
//Set<KeyType> keys = map.keySet();
//
//// Values iterate karne ke liye
//Collection<ValueType> values = map.values();
//
//// Key-Value pairs iterate karne ke liye
//Set<Map.Entry<KeyType, ValueType>> entries = map.entrySet();

import java.util.*;

public class MapTopic {

	public static void main(String[] args) {

		Map<Integer, String> map = new HashMap<>();
		map.put(null, null);
		map.put(101, "shivam raut");
		map.put(100, null);
		map.put(null, "For Null");
		map.put(102, "shivam soni");

		System.out.println("==========================");
		for (Integer key : map.keySet()) {
			System.out.println(key);
		}

		System.out.println("==========================");
		for (String val : map.values()) {
			System.out.println(val);
		}
		
		System.out.println("+++++++++++++++++++++++++++++");
		for (Map.Entry<Integer, String> entry : map.entrySet()) {
			System.out.println(entry.getValue()+"--->"+entry.getKey());
		}

	}
}