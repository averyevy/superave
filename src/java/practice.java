import java.util.*;
/*
Write a program that reads a number x and a character c from the keyboard.
The program outputs an empty square with the size x and border with character c.
 */
public class practice{
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
    public static void main(String[] args) {
        program_print_empty_square();
    }
}