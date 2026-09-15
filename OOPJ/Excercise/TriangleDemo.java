// Question 2 (Set 2): Triangle Class

class Triangle {
    private double side1;
    private double side2;
    private double side3;

    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public double getPerimeter() {
        return side1 + side2 + side3;
    }

    public double getArea() {
        double s = getPerimeter() / 2.0;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
}

public class TriangleDemo {
    public static void main(String[] args) {
        Triangle t = new Triangle(3, 4, 5);
        System.out.println("Triangle sides: 3, 4, 5");
        System.out.println("Perimeter: " + t.getPerimeter() + " units");
        System.out.println("Area: " + t.getArea() + " sq units");
    }
}
