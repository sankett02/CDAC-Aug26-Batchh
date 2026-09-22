public class EquilateralTriangle implements RegularPolygon {

    double sideLength;

    EquilateralTriangle(double sideLength) {
        this.sideLength = sideLength;
    }

    @Override
    public int getNumSides() {
        return 3;
    }

    @Override
    public double getSideLength() {
        return sideLength;
    }
}