package sanket.org;

import java.io.FileWriter;

public class FileWrite {

    public static void writeFile(String fileName, String data) {

        try {

            FileWriter wf = new FileWriter(fileName);

            wf.write(data);

            wf.close();

            System.out.println("Data successfully written in " + fileName);

        } catch (Exception e) {

            System.out.println("File Error found: " + e);
        }
    }
}
