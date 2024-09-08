import java.util.function.Function;
import java.util.concurrent.ExecutionException;

public class Functions {

    // basic function definition (method declaration)
    public static int add(int a, int b) {
        return a + b;
    }

    // function with javadoc annotations
    /**
     * multiplies two integers.
     *
     * @param x first integer.
     * @param y second integer.
     * @return the product of x and y.
     */
    public static int multiply(int x, int y) {
        return x * y;
    }

    // returning multiple values (using class or tuple-like structure)
    public static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static Pair multireturn(int a, int b) {
        return new Pair(a, b);
    }

    // default arguments via method overloading
    public static String greet(String name) {
        return "hello, " + name;
    }

    public static String greet() {
        return "hello, world!";
    }

    // pass by value (primitive types are passed by value)
    public static void modifyvalue(int x) {
        x = 100; // this won't change the original value
    }

    public static void modifyarray(int[] arr) {
        arr[0] = 100; // arrays are reference types, this will modify the original array
    }

    // higher-order functions (passing functions as parameters using functional interfaces)
    public static int applyfunction(Function<Integer, Integer> func, int val) {
        return func.apply(val);
    }

    // recursive function
    public static int factorial(int n) {
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }

    // nested functions (inner classes)
    public static class OuterClass {
        private int outerfield = 10;

        public void outermethod() {
            class InnerClass {
                public void innermethod() {
                    System.out.println("outer field: " + outerfield);
                }
            }

            InnerClass inner = new InnerClass();
            inner.innermethod();
        }
    }

    // private methods
    private static void privatefunction() {
        System.out.println("this is a private function.");
    }

    // lambda expressions (anonymous functions)
    public static void demonstratelambda() {
        // lambda function for summing two integers
        Function<Integer, Integer> square = x -> x * x;
        System.out.println("square of 5: " + square.apply(5));
    }

    // first-class functions (method references)
    public static void demonstratemethodreference() {
        // using method reference to refer to an existing method
        Function<String, Integer> lengthfunc = String::length;
        System.out.println("length of 'hello': " + lengthfunc.apply("hello"));
    }

    // variable length arguments (varargs)
    public static int sumall(int... numbers) {
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        return sum;
    }

    // static methods (belongs to class, not to instance)
    public static void staticmethod() {
        System.out.println("this is a static method.");
    }

    // instance methods (belongs to an object)
    public void instancemethod() {
        System.out.println("this is an instance method.");
    }

    // abstract methods (methods defined in abstract classes or interfaces)
    public interface Shape {
        double area();
    }

    public static class Circle implements Shape {
        private double radius;

        public Circle(double radius) {
            this.radius = radius;
        }

        @Override
        public double area() {
            return Math.PI * radius * radius;
        }
    }

    // cannot be overriden by subclasses
    public static final void displayMessage() {
        System.out.println("this method cannot be overridden.");
    }

    public static void main(String[] args) throws ExecutionException, InterruptedException {
        // basic function example
        System.out.println("sum of 3 and 4: " + add(3, 4));

        // annotated function example
        System.out.println("multiplication of 3 and 5: " + multiply(3, 5));

        // multiple return values example
        Pair result = multireturn(10, 20);
        System.out.println("multiple return: " + result.first + ", " + result.second);

        // default arguments example
        System.out.println(greet("alice"));
        System.out.println(greet());
        
        // private function
        privatefunction();

        // final function
        displayMessage();

        // pass by value example
        int value = 50;
        modifyvalue(value);
        System.out.println("original value (unchanged): " + value);

        int[] arr = {1, 2, 3};
        modifyarray(arr);
        System.out.println("modified array[0]: " + arr[0]);

        // higher-order functions example
        int doubled = applyfunction(x -> x * 2, 10);
        System.out.println("doubled value: " + doubled);

        // recursive function example
        System.out.println("factorial of 5: " + factorial(5));

        // nested function example
        OuterClass outer = new OuterClass();
        outer.outermethod();

        // lambda expression
        demonstratelambda();

        // method reference example
        demonstratemethodreference();

        // variable arguments example
        System.out.println("sum of all numbers: " + sumall(1, 2, 3, 4, 5));

        // static method example
        Functions.staticmethod();

        // instance method example
        Functions obj = new Functions();
        obj.instancemethod();

        // abstract method example
        Circle circle = new Circle(5);
        System.out.println("area of the circle: " + circle.area());
    }
}

/*
 * Modifiers and Keywords
 * 
 * Access
 * public       :   Makes the method accessible from anywhere.
 * protected    :	Accessible in the same package and subclasses.
 * private      :	Limits method access to within the same class.
 * (default)    :	Package-private; accessible within the same package.
 * 
 * Non-access
 * static       :	Belongs to the class rather than an instance of the class.
 * final        :	Prevents the method from being overridden by subclasses.
 * abstract     :	Requires subclasses to provide an implementation.
 * synchronized :	Ensures the method is thread-safe by allowing one thread to execute at a time.
 * native	    :   Declares that the method is implemented in another programming language.
 * strictfp	    :   Enforces strict IEEE 754 compliance for floating-point calculations.
*/


/* 
Chainable Functions

public class Chainable {
    private String value;

    public Chainable setValue(String value) {
        this.value = value;
        return this;
    }

    public Chainable printValue() {
        System.out.println("Value: " + value);
        return this;
    }

    public static void main(String[] args) {
        new Chainable().setValue("Hello").printValue();  // Method chaining
    }
}
 */
