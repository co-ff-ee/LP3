import java.util.Scanner;
public class A6_EightQueens {
    static final int N = 8;
    static int[][] board = new int[N][N];

    static boolean isSafe(int row, int col) {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 1) return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1) return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
            if (board[i][j] == 1) return false;
        return true;
    }

    static boolean solve(int row) {
        if (row == N) return true;
        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 1;
                if (solve(row + 1)) return true;
                board[row][col] = 0; // Backtrack
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter fixed queen row and column (0 to 7): ");
        int r = sc.nextInt(), c = sc.nextInt();
        if (r < 0 || r >= N || c < 0 || c >= N) {
            System.out.println("Invalid position."); return;
        }
        board[r][c] = 1;
        if (solve(0)) {
            System.out.println("Solution:");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) System.out.print(board[i][j] + " ");
                System.out.println();
            }
        } else System.out.println("No solution for this fixed position.");
        sc.close();
    }
}
