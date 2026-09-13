import java.util.Scanner;
class CopyArray{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size:");
        int n = sc.nextInt();

        int[] arr1 = new int[n];
        int[] arr2 = new int[n];

        System.out.println("Enter elements:");

        for(int i = 0; i<n; i++){
            arr1[i] = sc.nextInt();
        }
        for(int i = 0; i<n; i++){
            arr2[i] =arr1[i];
        }
        System.out.println("Copied Arry:");

        for(int i =0; i<n;i++){
            System.out.print(arr2[i] +"");
        }
        sc.close();
    }
}
