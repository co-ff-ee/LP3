import java.util.Scanner;
public class A5_BinomialCoefficient {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n: "); int n = sc.nextInt();
        System.out.print("Enter k: "); int k = sc.nextInt();
        if (n < 0 || k < 0 || k > n || n > 67) {
            System.out.println("Use values satisfying 0 <= k <= n <= 67."); return;
        }
        long[] dp = new long[k + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = Math.min(i, k); j >= 1; j--)
                dp[j] = dp[j] + dp[j - 1];
        System.out.println("C(" + n + ", " + k + ") = " + dp[k]);
        sc.close();
    }
}
