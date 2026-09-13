package OOPJ.Assignment;

import java.util.Scanner;

class Date {
    private int day;
    private int month;
    private int year;

    // Set date
    public void setDate(int day, int month, int year) {
        if (isValidDate(day, month, year)) {
            this.day = day;
            this.month = month;
            this.year = year;
            System.out.println("Date set successfully.");
        } else {
            System.out.println("Invalid date!");
        }
    }

    // Check leap year
    public boolean isLeapYear(int year) {
        return (year % 400 == 0) ||
                (year % 4 == 0 && year % 100 != 0);
    }

    // Return number of days in a month
    public int daysInMonth(int month, int year) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;

            case 4:
            case 6:
            case 9:
            case 11:
                return 30;

            case 2:
                return isLeapYear(year) ? 29 : 28;

            default:
                return 0;
        }
    }

    // Validate complete date
    public boolean isValidDate(int day, int month, int year) {

        if (year <= 0) {
            return false;
        }

        if (month < 1 || month > 12) {
            return false;
        }

        int maxDays = daysInMonth(month, year);

        return day >= 1 && day <= maxDays;
    }

    // Add days
    public void addDays(int days) {

        if (days < 0) {
            System.out.println("Days cannot be negative.");
            return;
        }

        while (days > 0) {
            int maxDays = daysInMonth(month, year);

            // If remaining days fit in current month
            if (day + days <= maxDays) {
                day += days;
                days = 0;
            }
            else {
                // Move to next month
                days -= (maxDays - day + 1);
                day = 1;

                month++;

                // Move to next year if necessary
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
        }
    }

    // Add months
    public void addMonths(int months) {

        if (months < 0) {
            System.out.println("Months cannot be negative.");
            return;
        }

        int totalMonths = (year * 12) + (month - 1) + months;

        year = totalMonths / 12;
        month = (totalMonths % 12) + 1;

        // Adjust day if new month has fewer days
        int maxDays = daysInMonth(month, year);

        if (day > maxDays) {
            day = maxDays;
        }
    }

    // Add years
    public void addYears(int years) {

        if (years < 0) {
            System.out.println("Years cannot be negative.");
            return;
        }

        year += years;

        // Feb 29 cannot exist in a non-leap year
        if (month == 2 && day == 29 && !isLeapYear(year)) {
            day = 28;
        }
    }

    // Display date
    public void display() {

        if (year == 0) {
            System.out.println("Date has not been set.");
        } else {
            System.out.printf("Date: %02d/%02d/%04d%n",
                    day, month, year);
        }
    }
}


public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Date date = new Date();

        int choice;

        do {
            System.out.println("\n===== DATE MENU =====");
            System.out.println("1. Set Date");
            System.out.println("2. Add Days");
            System.out.println("3. Add Months");
            System.out.println("4. Add Years");
            System.out.println("5. Display");
            System.out.println("6. Compare Dates");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter day: ");
                    int day = sc.nextInt();

                    System.out.print("Enter month: ");
                    int month = sc.nextInt();

                    System.out.print("Enter year: ");
                    int year = sc.nextInt();

                    date.setDate(day, month, year);
                    break;


                case 2:
                    System.out.print("Enter number of days to add: ");
                    int days = sc.nextInt();

                    date.addDays(days);

                    System.out.println("Days added successfully.");
                    break;


                case 3:
                    System.out.print("Enter number of months to add: ");
                    int months = sc.nextInt();

                    date.addMonths(months);

                    System.out.println("Months added successfully.");
                    break;


                case 4:
                    System.out.print("Enter number of years to add: ");
                    int years = sc.nextInt();

                    date.addYears(years);

                    System.out.println("Years added successfully.");
                    break;


                case 5:
                    date.display();
                    break;


                case 6:
                    System.out.println("Compare dates - NOT IMPLEMENTED YET.");
                    break;


                case 7:
                    System.out.println("Exiting program...");
                    break;


                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 7);

        sc.close();
    }
}