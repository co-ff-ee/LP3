import java.util.Scanner;
public class A1_Fibonacci {
    static int calls = 0;
    static int fib(int n) {
        calls++;
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of terms (1 to 30): ");
        int n = sc.nextInt();
        if (n < 1 || n > 30) { System.out.println("Invalid input."); return; }

        int a = 0, b = 1;
        System.out.print("Iterative: ");
        for (int i = 0; i < n; i++) {
            System.out.print(a + " ");
            int next = a + b; a = b; b = next;
        }
        System.out.print("\nRecursive: ");
        for (int i = 0; i < n; i++) System.out.print(fib(i) + " ");
        System.out.println("\nTotal recursive calls: " + calls);
        sc.close();
    }
}
