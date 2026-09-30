package sanket.org;

import java.io.FileReader;

public class FileRead {

    public static void encrypt() {

        try {

            FileReader rf = new FileReader("Original.txt");

            String data = "";
            int ch;

            while ((ch = rf.read()) != -1) {

                data = data + (char)(ch + 3);
            }

            rf.close();

            FileWrite.writeFile("Encrypted.txt", data);

            System.out.println("Encryption Completed");

        } catch (Exception e) {

            System.out.println("Encryption Error: " + e);
        }
    }


    public static void decrypt() {

        try {

            FileReader rf = new FileReader("Encrypted.txt");

            String data = "";
            int ch;

            while ((ch = rf.read()) != -1) {

                data = data + (char)(ch - 3);
            }

            rf.close();

            FileWrite.writeFile("Decrypted.txt", data);

            System.out.println("Decryption Completed");

        } catch (Exception e) {

            System.out.println("Decryption Error: " + e);
        }
    }
}

