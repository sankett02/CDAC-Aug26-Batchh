class Rectangle {
    protected double length;
    protected double breadth;

    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public void printArea() {
        System.out.println("Area: " + (length * breadth));
    }

    public void printPerimeter() {
        System.out.println("Perimeter: " + (2 * (length + breadth)));
    }
}

class Square extends Rectangle {
    public Square(double side) {
        super(side, side);
    }
}

public class RectangleSquareDemo {
    public static void main(String[] args) {
        System.out.println("--- Rectangle ---");
        Rectangle rect = new Rectangle(7.5, 4.0);
        rect.printArea();
        rect.printPerimeter();

        System.out.println("\n--- Square ---");
        Square sq = new Square(5.0);
        sq.printArea();
        sq.printPerimeter();
    }
}
