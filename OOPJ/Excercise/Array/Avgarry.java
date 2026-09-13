import java.util.Scanner;

class Avgarry{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size:");
        int n = sc.nextInt();

        int[]arr = new int[n];

        for(int i =0; i<n; i++){
            arr[i]= sc.nextInt();
        }

        int sum =0;

        for(int i =0; i < n; i++){
            sum = sum+arr[i];
        }

        double average =(double) sum/n;

        System.out.println("Average ="+ average);
        sc.close();
    }
}
