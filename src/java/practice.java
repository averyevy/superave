import java.util.*;
public class practice{
    public static void main(String[] args) {
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
}
