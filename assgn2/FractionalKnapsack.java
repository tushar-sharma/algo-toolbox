import java.util.Scanner;
import java.util.Arrays;

class Pair implements Comparable<Pair> {
    public final double values;
    public final int index;

    public Pair(double values, int index) {
        this.values = values;
        this.index = index;
    }

    @Override
    public int compareTo(Pair other) {
        //multiply by -1 for descending order
        //return -1 * Integer.valueOf(this.values).compareTo(other.values);
        return Double.valueOf(this.values).compareTo(other.values);
    }
}
/*
 * Fractional Knapsack
 */
public class FractionalKnapsack {
    private static double getOptimalValue(int capacity, int[] values, int[] weights) {

        double value = 0.0;
        Pair[] weight_value = new Pair[values.length];
        int[] index = new int[values.length];

        for (int i = 0; i < values.length; ++i) {
            index[i] = i;
            weight_value[i] = new Pair((double)values[i] / weights[i], index[i]);
        }

        Arrays.sort(weight_value);

        // Java uses quick sort to sort the arrays which has
        // O(n log n) as average complexity and
        // O(n^2) as worst case
        // but array of object is sorted using merge sort
        // http://codeforces.com/blog/entry/7108

        //for n items/*

        for (int i = values.length - 1; i >= 0; --i) {

            if (capacity == 0) {
                return value;
            }

            int min_weight = capacity;

            //get the key
            if (weights[weight_value[i].index]  < min_weight) {
                min_weight = weights[weight_value[i].index];
            }

            value = value + ((double) min_weight * weight_value[i].values);
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
