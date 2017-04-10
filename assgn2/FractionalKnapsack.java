import java.util.Scanner;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.Map;

/*
 * Fractional Knapsack
 * Status: Pending
 */
public class FractionalKnapsack {
    private static double getOptimalValue(int capacity, int[] values, int[] weights) {
        double value = 0.0000;
        double[] per_value_weights = new double[values.length];

        Map<Double, Integer> keep_ratio_weights  = new TreeMap<Double, Integer>();

        for (int i = 0; i < values.length; ++i) {
            per_value_weights[i] = (double)values[i] / weights[i];
            keep_ratio_weights.put(per_value_weights[i], weights[i]);
        }

        // Java uses quick sort to sort the arrays which has
        // O(n log n) as average complexity and
        // O(n^2) as worst case
        // but array of object is sorted using merge sort
        // http://codeforces.com/blog/entry/7108

        //for n items
        for (int i = values.length - 1; i >= 0; --i) {

            if (capacity == 0) {
                return value;
            }

            int min_weight = capacity;

            if (keep_ratio_weights.get(keep_ratio_weights.keySet().toArray()[i])  < min_weight) {
                min_weight = keep_ratio_weights.get(keep_ratio_weights.keySet().toArray()[i]);
            }

            value = value + (min_weight * (double)keep_ratio_weights.keySet().toArray()[i]);
            capacity = capacity - min_weight;
        }

        return value;
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int capacity = scanner.nextInt();
        int[] values = new int[n];
        int[] weights = new int[n];

        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
            weights[i] = scanner.nextInt();
        }

        System.out.println(getOptimalValue(capacity, values, weights));
    }
}
