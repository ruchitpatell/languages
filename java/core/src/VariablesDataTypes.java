public class VariablesDataTypes {
        public static void main(String[] args) {
            // primitive data types
            int age = 25;
            double price = 12.99;
            char grade = 'A';
            boolean isActive = true;
    
            System.out.println("Age: " + age);
            System.out.println("Price: " + price);
            System.out.println("Grade: " + grade);
            System.out.println("Active: " + isActive);
    
            // type casting (double to int)
            int roundedPrice = (int) price;
            System.out.println("Rounded price: " + roundedPrice);
    
            // non-primitive data type: String
            String name = "John";
            System.out.println("Name: " + name);
        }
}
