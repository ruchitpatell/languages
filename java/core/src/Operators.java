public class Operators {
    public static void main(String[] args) {
        // arithmetic
        int x = 5, y = 3;
        System.out.println("Addition: " + (x + y));
        System.out.println("Subtraction: " + (x - y));
        System.out.println("Multiplication: " + (x * y));
        System.out.println("Division: " + (x / y));
        System.out.println("Modulus: " + (x % y));

        // comparison operators
        System.out.println("x == y: " + (x == y));  // false
        System.out.println("x != y: " + (x != y));  // true
        System.out.println("x > y: " + (x > y));  // true
        System.out.println("x < y: " + (x < y));  // false

        // logical operators
        boolean a = true, b = false;
        System.out.println("a AND b: " + (a && b));  // false
        System.out.println("a OR b: " + (a || b));  // true
        System.out.println("NOT a: " + (!a));  // false
    }
}
