import java.util.Scanner;

class Complex
{
    private int number1;
    private int number2;

    public void setNumber1(int number1)
    {
        this.number1 = number1;
    }

    public void setNumber2(int number2)
    {
        this.number2 = number2;
    }

    public int getNumber1()
    {
        return number1;
    }

    public int getNumber2()
    {
        return number2;
    }

    public int computeComplexNumber()
    {
        return number1 * number2;
    }
}

class ComplexNumberDemo
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        Complex[] arr = new Complex[5];

        for(int i = 0; i < 5; i++)
        {
            arr[i] = new Complex();

            System.out.println("Enter number1:");
            int n1 = sc.nextInt();

            System.out.println("Enter number2:");
            int n2 = sc.nextInt();

            arr[i].setNumber1(n1);
            arr[i].setNumber2(n2);
        }

        System.out.println("Results:");

        for(int i = 0; i < 5; i++)
        {
            System.out.println(
                arr[i].computeComplexNumber()
            );
        }
    }
}