package sanket.org;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int choice;

        Scanner sc = new Scanner(System.in);

        do {

            System.out.println("================= Menu =================");
            System.out.println("1. Encryption");
            System.out.println("2. Decryption");
            System.out.println("3. Exit");
            System.out.print("Enter Your Choice: ");

            choice = sc.nextInt();

            switch (choice) {

            case 1:
                System.out.println("Encryption Selected");
                FileRead.encrypt();
                break;

            case 2:
                System.out.println("Decryption Selected");
                FileRead.decrypt();
                break;

            case 3:
                System.out.println("Program exit");
                break;

            default:
                System.out.println("Invalid Choice");
            }

        } while (choice != 3);

        sc.close();
    }
}

