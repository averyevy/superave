import java.util.*;
/*
Write a program that reads a number n <= 20 from the keyboard
and prints the spiral of asterisks on the screen as shown below.
 */
public class practice {
    public static void program_print_empty_square(){
        Scanner scan = new Scanner (System.in);
        int x = scan.nextInt();
        String c = scan.next();
        for (int rows=0; rows<x; rows++) {
            for (int cols=0; cols<x; cols++) {
                if (rows == 0 || rows == x-1 || cols == 0 || cols == x-1) {
                    System.out.print(c);
                }
                else {
                    System.out.print(" ");
                }
            }
            System.out.println("");
        }
    }

    public static void program_print_spiral_asterisks(){
        // Create row and col
        // to traverse rows and columns
        Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        int row = 0, col = size;

        int boundary = size;
        int sizeLeft = size - 1;
        int flag = 1;

        int[][] matrix = new int[size][size];

        char move = 'l';
        for (int i = 1; i < size * (size) + 1; i++) {

            // switch-case to determine the next index
            switch (move) {

                // If right, go right
                case 'r':
                    col += 1;
                    break;

                // if left, go left
                case 'l':
                    col -= 1;
                    break;

                // if up, go up
                case 'u':
                    row -= 1;
                    break;

                // if down, go down
                case 'd':
                    row += 1;
                    break;
            }
            // Assign the value
            if (sizeLeft <= 0) {
                break;
            }
            matrix[row][col] = 1;

            // Check if the matrix
            // has reached array boundary
            if (i == boundary) {

                // Add the left size for the next boundary
                boundary += sizeLeft;

                // If 2 rotations has been made,
                // decrease the size left by 1
                if (flag != 2) {
                    flag = 2;
                } else {
                    flag = 1;
                    sizeLeft -= 2;
                }

                // switch-case to rotate the movement
                switch (move) {

                    // if right, rotate to down
                    case 'r':
                        move = 'u';
                        break;

                    // if down, rotate to left
                    case 'd':
                        move = 'r';
                        break;

                    // if left, rotate to up
                    case 'l':
                        move = 'd';
                        break;

                    // if up, rotate to right
                    case 'u':
                        move = 'l';
                        break;
                }
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] > 0) {
                    System.out.print("*");
                } else {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }


    }
    public static void main(String[] args) {
        program_print_spiral_asterisks();
    }
}