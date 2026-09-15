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

        // Call method of 'Shape' class by object of 'Square' class
        square.printShape();

        // Call method of 'Rectangle' class by object of 'Square' class
        square.printRectangle();

        // Call method of 'Square' class
        square.printSquare();
    }
}
