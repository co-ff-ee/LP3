import java.util.Scanner;
public class A4_ZeroOneKnapsack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of items: ");
        int n = sc.nextInt();
        if (n < 0) { System.out.println("Invalid number of items."); return; }
        int[] weight = new int[n], value = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter weight and value of item " + (i + 1) + ": ");
            weight[i] = sc.nextInt(); value[i] = sc.nextInt();
            if (weight[i] <= 0 || value[i] < 0) {
                System.out.println("Invalid item data."); return;
            }
        }
        System.out.print("Enter capacity: ");
        int capacity = sc.nextInt();
        if (capacity < 0) { System.out.println("Invalid capacity."); return; }

        int[][] dp = new int[n + 1][capacity + 1];
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                if (weight[i - 1] <= w)
                    dp[i][w] = Math.max(value[i - 1] + dp[i - 1][w - weight[i - 1]],
                                        dp[i - 1][w]);
                else dp[i][w] = dp[i - 1][w];
            }
        }
        System.out.println("Maximum value: " + dp[n][capacity]);
        sc.close();
    }
}
