import java.util.Scanner;
class SumArry{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size :");
        int n = sc.nextInt();

        int[] arr = new int[n];

        System.out.println("Eneter Elements:");

        for(int i = 0; i<n ; i++){
            arr[i] = sc.nextInt();
        }

        int sum =0;

        for(int i =0; i<n ; i++){
            sum+=arr[i];
        }

        System.out.println("Sum =" +sum);
        sc.close();
    }
}