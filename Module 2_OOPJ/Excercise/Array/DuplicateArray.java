import java.util.Scanner;

class DuplicateArray
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        for(int i = 0; i < n; i++)
        {
            arr[i] = sc.nextInt();
        }

        System.out.println("Duplicate values:");

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    System.out.println(arr[i]);
                    break;
                }
            }
        }
    }
}