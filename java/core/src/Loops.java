public class Loops {
    public static void main(String[] args) {
        // for loop
        for (int i = 0; i < 5; i++) {
            System.out.println("For loop count: " + i);
        }

        // while loop
        int count = 0;
        while (count < 5) {
            System.out.println("While loop count: " + count);
            count++;
        }

        // do-while loop (runs at least once)
        int j = 0;
        do {
            System.out.println("Do-while loop count: " + j);
            j++;
        } while (j < 5);

        // for each
        int[] numbers = {1, 2, 3, 4, 5};
        for (int num : numbers) {
            System.out.println("Array element: " + num);
        }
    }
}
