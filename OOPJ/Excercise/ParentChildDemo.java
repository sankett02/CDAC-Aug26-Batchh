class Parent {
    public void printParent() {
        System.out.println("This is parent class");
    }
}

class Child extends Parent {
    public void printChild() {
        System.out.println("This is child class");
    }
}

public class ParentChildDemo {
    public static void main(String[] args) {
        Parent parentObj = new Parent();
        Child childObj = new Child();

        // 1 - Method of parent class by object of parent class
        parentObj.printParent();

        // 2 - Method of child class by object of child class
        childObj.printChild();

        // 3 - Method of parent class by object of child class
        childObj.printParent();
    }
}
