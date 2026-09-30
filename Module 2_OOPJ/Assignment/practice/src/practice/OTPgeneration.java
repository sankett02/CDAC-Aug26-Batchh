//package practice;
//import java.util.*;
//import java.util.random.*;
//import java.util.function.*;
//public class OTPgeneration {
//
//	public static void main(String[] args) {
//		Supplier<String>OtpGeneration =()->{
//			Random r = new Random();
//			String vowels = "AEIOU";
//			char firstChar = vowels.charAt(r.nextInt(5));
//					return""+firstChar
//							+r.nextInt(10)
//							+r.nextInt(10)
//							+r.nextInt(10)
//							+r.nextInt(10);
//							
//		};
//		
//		System.out.println(OtpGeneration.get());
//
//	}
//
//}
package practice;

import java.util.Random;
import java.util.function.Supplier;

public class OTPgeneration {

    public static void main(String[] args) {

        // Create Random object
        Random random = new Random();

        // Create Supplier to generate OTP
        Supplier<String> otpGeneration = () -> {

            String vowels = "AEIOU";

            // Generate first character
            char firstChar = vowels.charAt(random.nextInt(vowels.length()));

            // Generate 4 random digits
            int digit1 = random.nextInt(10);
            int digit2 = random.nextInt(10);
            int digit3 = random.nextInt(10);
            int digit4 = random.nextInt(10);

            // Return OTP
            return "" + firstChar + digit1 + digit2 + digit3 + digit4;
        };

        // Call Supplier
        String otp = otpGeneration.get();

        // Print OTP
        System.out.println("Generated OTP: " + otp);
    }
}