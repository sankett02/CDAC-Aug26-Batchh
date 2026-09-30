// Question 1: Parent and Child Class Inheritance

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

        System.out.println("1 - Calling parent method by parent object:");
        parentObj.printParent();

        System.out.println("\n2 - Calling child method by child object:");
        childObj.printChild();

        System.out.println("\n3 - Calling parent method by child object:");
        childObj.printParent();
    }
}
