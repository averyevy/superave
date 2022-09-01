import java.util.*;
public class practice {
    public static void program_print_empty_square(){
        /*
    Write a program that reads a number x and a character c from the keyboard.
    The program outputs an empty square with the size x and border with character c.
     */
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
        /*
    Write a program that reads a number n <= 20 from the keyboard
    and prints the spiral of asterisks on the screen as shown below.
     */
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
    public static void program_print_maze_answer_accuracy(){
        /*
    You will be given a map of a maze and a path. Check if the path is a correct way to the exit.
    You will start at position (1, 1), and exit is at (1, m - 1). An example maze of size (7, 6) is given below.
    Starting and exit locations are shown as 'S' and 'E'. A path is shown with red color to the exit.
    You will first read the size of the maze (n, m). Then the maze will be given; '#'s are walls, '.'s are empty locations.
    The size of the maze will not be more than (20, 20). The path is given as a string composed of four different letters;
    'l' means left, 'r' means right, 'u' means 'up', and 'd' means 'down'.
    You will write 'Right path!' if the path leads to the exit from the starting location, otherwise write 'Wrong path!' on the screen.

    Example input:
    7 6
    ######
    #.#...
    #.#..#
    #..#.#
    ##...#
    #..#.#
    ######
    ddrdrruulurr
    */

        Scanner scan = new Scanner (System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        char[][] maze = new char [n][m];
        for (int i=0; i<n; i++) {
            String v = scan.next();
            for (int j=0; j<m ; j++) {
                maze[i][j] = v.charAt(j);
            }
        }
        String path = scan.next();
        int r = 1;
        int c = 1;
        int valid = 1;
        for (int i=0; i < path.length(); i++) {
            if (path.charAt(i) == 'd')
                r++;
            if (path.charAt(i) == 'u')
                r--;
            if (path.charAt(i) == 'r')
                c++;
            if (path.charAt(i) == 'l')
                c--;
            if (r==1 && c==m-1) {
                if (i!=path.length()-1)
                    valid = 0;
                break;
            }
            if (maze[r][c] == '#') {
                valid = 0;
                break;
            }
        }
        if (valid==1 && r==1 && c==m-1)
            System.out.println("Right path!");
        else
            System.out.println("Wrong path!");
    public static void main(String[] args) {
        program_print_spiral_asterisks();
    }
}