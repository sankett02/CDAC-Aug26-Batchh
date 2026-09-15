// Question 4 (Set 2): Complex Numbers

import java.util.Scanner;

class Complex {
    private double real;
    private double imag;

    public Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    public Complex add(Complex c) {
        return new Complex(this.real + c.real, this.imag + c.imag);
    }

    public Complex subtract(Complex c) {
        return new Complex(this.real - c.real, this.imag - c.imag);
    }

    public Complex multiply(Complex c) {
        return new Complex((this.real * c.real) - (this.imag * c.imag),
                           (this.real * c.imag) + (this.imag * c.real));
    }

    public void display() {
        System.out.println(real + (imag >= 0 ? " + " : " - ") + Math.abs(imag) + "i");
    }
}

public class ComplexDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter real and imaginary parts of first complex number: ");
        Complex c1 = new Complex(sc.nextDouble(), sc.nextDouble());

        System.out.print("Enter real and imaginary parts of second complex number: ");
        Complex c2 = new Complex(sc.nextDouble(), sc.nextDouble());

        System.out.print("\nSum: ");
        c1.add(c2).display();

        System.out.print("Difference: ");
        c1.subtract(c2).display();

        System.out.print("Product: ");
        c1.multiply(c2).display();

        sc.close();
    }
}
