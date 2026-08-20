public class UninitializedVariables {
    public static void main(String[] args) {

        byte a = 12;
        short b = 233;
        int c = 45;
        long d = 12L;
        float e = 4.5f;
        double f = 3554.8;
        char g = '\u0000';
        boolean h = false;

        System.out.println("byte: " + a);
        System.out.println("short: " + b);
        System.out.println("int: " + c);
        System.out.println("long: " + d);
        System.out.println("float: " + e);
        System.out.println("double: " + f);
        System.out.println("char: " + g);
        System.out.println("boolean: " + h);
    }
}
