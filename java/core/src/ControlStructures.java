public class ControlStructures {
    public static void main(String[] args) {
        // if-else statement
        int a = 10;
        if (a > 5) {
            System.out.println("a is greater than 5");
        } else {
            System.out.println("a is less than or equal to 5");
        }

        // for loop
        for (int i = 0; i < 3; i++) {
            System.out.println("For loop iteration: " + i);
        }

        // while loop
        int counter = 0;
        while (counter < 3) {
            System.out.println("While loop iteration: " + counter);
            counter++;
        }

        // do-while loop (executes at least once)
        int j = 0;
        do {
            System.out.println("Do-while loop iteration: " + j);
            j++;
        } while (j < 3);

        // switch statement
        int day = 2;
        switch (day) {
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            default:
                System.out.println("Other day");
        }
    }
}
