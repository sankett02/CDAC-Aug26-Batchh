package practice;
import java.time.LocalDate;
import java.util.*;
import java.util.function.Supplier;

public class LambadaExercise5 {

	public static void main(String[] args) {
		Supplier<LocalDate>currentDate = ()->LocalDate.now();
		
		System.out.println("Current Date: " +currentDate.get());
	}
}
