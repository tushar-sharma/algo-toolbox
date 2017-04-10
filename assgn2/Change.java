import java.util.Scanner;
/*
 * Changing Money
 * The goal in this problem is to find the minimum number of coins needed to change the input value
 * (an integer) into coins with denominations 1, 5, and 10.
 */
public class CoinChange {

    private static int getChange(int m) {
        int[] denomination = {1, 5, 10};
        int number_of_coins = 0;
        int choice = denomination.length - 1;

        for(int i = denomination.length - 1; i >= 0; --i) {
            while (m - denomination[i] >= 0) {
                number_of_coins++;
                m = m - denomination[i];
            }
        }

        return number_of_coins;
    }

    private static void testCoinChange() {
        assert getChange(2) == 2 : "FAILED for input 2.";
        assert getChange(28) == 6 : "FAILED for input 28.";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();

        System.out.println(getChange(m));
        //testCoinChange();

    }
}
