package practice;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;


// Only Transaction class here
class Transaction {

    private int txId;
    private LocalDate txDate;
    private float txAmount;
    private boolean txStatus;
    private boolean txArrears;

    public Transaction(int txId, LocalDate txDate,
                       float txAmount,
                       boolean txStatus,
                       boolean txArrears) {

        this.txId = txId;
        this.txDate = txDate;
        this.txAmount = txAmount;
        this.txStatus = txStatus;
        this.txArrears = txArrears;
    }

    public int getTxId() {
        return txId;
    }

    public LocalDate getTxDate() {
        return txDate;
    }

    public float getTxAmount() {
        return txAmount;
    }

    public boolean isTxStatus() {
        return txStatus;
    }

    public boolean isTxArrears() {
        return txArrears;
    }

    @Override
    public String toString() {
        return "Transaction{" +
                "txId=" + txId +
                ", txDate=" + txDate +
                ", txAmount=" + txAmount +
                ", txStatus=" + txStatus +
                ", txArrears=" + txArrears +
                '}';
    }
}


// ONLY ONE Main class
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // OTP
        Supplier<String> otpGenerator = () -> {

            Random r = new Random();

            String vowels = "AEIOU";

            char firstChar =
                    vowels.charAt(r.nextInt(5));

            return "" + firstChar
                    + r.nextInt(10)
                    + r.nextInt(10)
                    + r.nextInt(10)
                    + r.nextInt(10);
        };

        System.out.println("Generated OTP: "
                + otpGenerator.get());


        // Collection
        ArrayList<Transaction> transactions =
                new ArrayList<>();


        // Input for 5 transactions
        for (int i = 0; i < 5; i++) {

            System.out.println(
                    "\nEnter details for Transaction "
                    + (i + 1));

            System.out.print("Enter Transaction ID: ");
            int id = sc.nextInt();

            System.out.print(
                    "Enter Transaction Date (yyyy-mm-dd): ");
            LocalDate date =
                    LocalDate.parse(sc.next());

            System.out.print("Enter Transaction Amount: ");
            float amount = sc.nextFloat();

            System.out.print(
                    "Enter Transaction Status (true/false): ");
            boolean status = sc.nextBoolean();

            System.out.print(
                    "Enter Transaction Arrears (true/false): ");
            boolean arrears = sc.nextBoolean();

            Transaction t = new Transaction(
                    id,
                    date,
                    amount,
                    status,
                    arrears
            );

            transactions.add(t);
        }


        // 1. Amount > 5000
        Predicate<Transaction> amountCheck =
                t -> t.getTxAmount() > 5000;

        System.out.println(
                "\n===== AMOUNT > 5000 =====");

        transactions.stream()
                .filter(amountCheck)
                .forEach(System.out::println);


        // 2. Status false
        Predicate<Transaction> statusCheck =
                t -> !t.isTxStatus();

        System.out.println(
                "\n===== STATUS = FALSE =====");

        transactions.stream()
                .filter(statusCheck)
                .forEach(System.out::println);


        // 3. Amount Due
        Function<Transaction, Float> amountDue =
                t -> {

                    if (t.isTxArrears()) {

                        return t.getTxAmount()
                                + 500
                                + (t.getTxAmount() * 0.18f);

                    } else {

                        return t.getTxAmount();
                    }
                };


        System.out.println(
                "\n===== AMOUNT DUE =====");

        for (Transaction t : transactions) {

            System.out.println(
                    "Transaction ID: "
                    + t.getTxId()
                    + " | Amount Due: "
                    + amountDue.apply(t)
            );
        }

        sc.close();
    }
}