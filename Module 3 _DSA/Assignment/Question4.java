import java.util.ArrayList;
import java.util.Scanner;

public class Question4 {

    private static ArrayList<Integer> queue = new ArrayList<>();

    public static void addStudent(int id) {
        queue.add(id);
        System.out.println("-> Student " + id + " added to the queue.");
    }

    public static void submitAssignment() {
        if (queue.isEmpty()) {
            System.out.println("-> Queue is empty! No student is waiting to submit.");
            return;
        }
        int studentId = queue.remove(0);
        System.out.println("-> Student " + studentId + " submitted assignment and left the queue.");
    }

    public static void searchStudent(int id) {
        int index = queue.indexOf(id);
        if (index != -1) {
            System.out.println("-> Output: Student " + id + " is waiting in queue (Position: " + (index + 1) + ").");
        } else {
            System.out.println("-> Output: Student " + id + " is NOT currently waiting in queue.");
        }
    }

    public static void displayQueue() {
        if (queue.isEmpty()) {
            System.out.println("-> Current Queue is Empty.");
        } else {
            System.out.println("-> Current Queue: " + queue);
        }
    }

    public static void countStudents() {
        System.out.println("-> Current number of students waiting: " + queue.size());
    }

    public static void runDemo() {
        System.out.println("=== RUNNING AUTOMATED DEMO FOR QUESTION 4 ===");
        
        System.out.println("\n--- Step 1: Adding Initial Students [105, 112, 108, 101, 115] ---");
        addStudent(105);
        addStudent(112);
        addStudent(108);
        addStudent(101);
        addStudent(115);
        displayQueue();

        System.out.println("\n--- Step 2: Student 105 Submits Assignment ---");
        submitAssignment();
        displayQueue();

        System.out.println("\n--- Step 3: Search for Student ID 101 ---");
        searchStudent(101);

        System.out.println("\n--- Step 4: Count Waiting Students ---");
        countStudents();

        System.out.println("\n--- Step 5: Processing until Queue is Empty ---");
        submitAssignment();
        submitAssignment();
        submitAssignment();
        submitAssignment();
        displayQueue();
        countStudents();
        
        System.out.println("\n--- Step 6: Submitting on Empty Queue ---");
        submitAssignment();
        
        System.out.println("\n=============================================");
    }

    public static void main(String[] args) {
        if (args.length > 0 && args[0].equalsIgnoreCase("demo")) {
            runDemo();
            return;
        }

        Scanner scanner = new Scanner(System.in);
        
        System.out.println("==================================================");
        System.out.println("   C-DAC Student Queue Management System");
        System.out.println("==================================================");

        while (true) {
            System.out.println("\n--- MENU OPTIONS ---");
            System.out.println("1. Add Student");
            System.out.println("2. Submit Assignment (Remove from front)");
            System.out.println("3. Search Student");
            System.out.println("4. Display Queue");
            System.out.println("5. Count Students");
            System.out.println("6. Run Automated Demo");
            System.out.println("7. Exit");
            System.out.print("Enter your choice (1-7): ");

            if (!scanner.hasNextInt()) {
                System.out.println("Invalid input! Please enter a number between 1 and 7.");
                scanner.next();
                continue;
            }

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter Student ID to add: ");
                    int addId = scanner.nextInt();
                    addStudent(addId);
                    break;
                case 2:
                    submitAssignment();
                    break;
                case 3:
                    System.out.print("Enter Student ID to search: ");
                    int searchId = scanner.nextInt();
                    searchStudent(searchId);
                    break;
                case 4:
                    displayQueue();
                    break;
                case 5:
                    countStudents();
                    break;
                case 6:
                    runDemo();
                    break;
                case 7:
                    System.out.println("Exiting Student Queue Management System. Goodbye!");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice! Please select between 1 and 7.");
            }
        }
    }
}
