import java.util.Arrays;
import java.util.Scanner;
public class A2_JobSequencing {
    static class Job {
        int id, deadline, profit;
        Job(int id, int deadline, int profit) {
            this.id = id; this.deadline = deadline; this.profit = profit;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of jobs: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid number of jobs."); return; }
        Job[] jobs = new Job[n];
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            System.out.print("Enter deadline and profit for job " + (i + 1) + ": ");
            int d = sc.nextInt(), p = sc.nextInt();
            if (d <= 0 || p < 0) { System.out.println("Invalid job data."); return; }
            jobs[i] = new Job(i + 1, d, p);
            maxDeadline = Math.max(maxDeadline, d);
        }
        Arrays.sort(jobs, (x, y) -> Integer.compare(y.profit, x.profit));
        int slotsCount = Math.min(maxDeadline, n);
        int[] slots = new int[slotsCount + 1];
        Arrays.fill(slots, -1);
        int totalProfit = 0;
        for (Job job : jobs) {
            for (int s = Math.min(job.deadline, slotsCount); s >= 1; s--) {
                if (slots[s] == -1) {
                    slots[s] = job.id; totalProfit += job.profit; break;
                }
            }
        }
        System.out.print("Job sequence: ");
        for (int s = 1; s <= slotsCount; s++)
            if (slots[s] != -1) System.out.print("J" + slots[s] + " ");
        System.out.println("\nMaximum profit: " + totalProfit);
        sc.close();
    }
}
