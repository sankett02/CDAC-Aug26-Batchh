public class LargestNumber {
    public static  void main(String[] args){
        int a =20;
        int b =25;
        int c =15;
        int largest;
        if(a>b && a>c){
            largest=a;
        } else if (b>a) {
            largest=b;
        }
        else {
            largest=c;
        }
        System.out.println("The Largest Number =" + largest);
    }
}
