// Question 4: Shape Class Hierarchy

public class ShapeHierarchyDemo {

    static class Shape {
        public void printShape() {
            System.out.println("This is shape");
        }
    }

    static class Rectangle extends Shape {
        public void printRectangle() {
            System.out.println("This is rectangular shape");
        }
    }

    static class Circle extends Shape {
        public void printCircle() {
            System.out.println("This is circular shape");
        }
    }

    static class Square extends Rectangle {
        public void printSquare() {
            System.out.println("Square is a rectangle");
        }
    }

    public static void main(String[] args) {
        Square square = new Square();

        System.out.println("1 - Calling method of Shape class by Square object:");
        square.printShape();

        System.out.println("\n2 - Calling method of Rectangle class by Square object:");
        square.printRectangle();
    }
}
