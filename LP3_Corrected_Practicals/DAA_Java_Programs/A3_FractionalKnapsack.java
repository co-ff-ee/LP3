import java.util.Arrays;
import java.util.Scanner;
public class A3_FractionalKnapsack {
    static class Item {
        double value, weight;
        Item(double value, double weight) { this.value = value; this.weight = weight; }
        double ratio() { return value / weight; }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of items: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid number of items."); return; }
        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter value and weight of item " + (i + 1) + ": ");
            double v = sc.nextDouble(), w = sc.nextDouble();
            if (v < 0 || w <= 0) { System.out.println("Invalid item data."); return; }
            items[i] = new Item(v, w);
        }
        System.out.print("Enter capacity: ");
        double capacity = sc.nextDouble();
        if (capacity < 0) { System.out.println("Invalid capacity."); return; }

        Arrays.sort(items, (x, y) -> Double.compare(y.ratio(), x.ratio()));
        double total = 0;
        for (Item item : items) {
            if (capacity == 0) break;
            if (item.weight <= capacity) {
                total += item.value; capacity -= item.weight;
            } else {
                total += item.ratio() * capacity; capacity = 0;
            }
        }
        System.out.println("Maximum value: " + total);
        sc.close();
    }
}
