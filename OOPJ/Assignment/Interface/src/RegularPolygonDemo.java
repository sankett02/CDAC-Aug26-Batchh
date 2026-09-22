public class RegularPolygonDemo {

    public static void main(String[] args) {

        RegularPolygon triangle =
                new EquilateralTriangle(10);

        RegularPolygon square =
                new Square(5);

        System.out.println("Triangle");

        System.out.println("Number of sides: "
                + triangle.getNumSides());

        System.out.println("Side length: "
                + triangle.getSideLength());

        System.out.println("Perimeter: "
                + triangle.getPerimeter());

        System.out.println("Interior angle: "
                + triangle.getInteriorAngle());

        System.out.println("\nSquare");

        System.out.println("Number of sides: "
                + square.getNumSides());

        System.out.println("Side length: "
                + square.getSideLength());

        System.out.println("Perimeter: "
                + square.getPerimeter());

        System.out.println("Interior angle: "
                + square.getInteriorAngle());

        RegularPolygon[] polygons = {
                triangle,
                square
        };

        System.out.println("\nTotal sides: "
                + RegularPolygon.totalSides(polygons));
    }
}