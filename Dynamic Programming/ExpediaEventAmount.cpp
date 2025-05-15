public class MaximizeEventAmountTabulation {
    static class Item {
        String id;
        int time;
        int amount;

        public Item(String id, int time, int amount) {
            this.id = id;
            this.time = time;
            this.amount = amount;
        }
    }

    public static void main(String[] args) {
        Item[] items = {
            new Item("B1", 6, 200),
            new Item("B2", 10, 160),
            new Item("B3", 130, 200),
            new Item("B4", 12, 400)
        };
        int totalTime = 60;
        int n = items.length;

        // dp[i][w] will store the maximum amount using items up to i-1 (0-indexed)
        // with a total weight capacity of w
        int[][] dp = new int[n + 1][totalTime + 1];

        // Build table dp[][] in bottom-up manner
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= totalTime; w++) {
                if (i == 0 || w == 0) { // Base case: no items or no capacity
                    dp[i][w] = 0;
                } else if (items[i-1].time <= w) { // If current item (i-1) can be included
                    // Max of:
                    // 1. Including item[i-1]: its amount + amount from remaining capacity with previous items
                    // 2. Excluding item[i-1]: amount from previous items with same capacity
                    dp[i][w] = Math.max(
                        items[i-1].amount + dp[i-1][w - items[i-1].time],
                        dp[i-1][w]
                    );
                } else { // If current item's time is more than current capacity w, exclude it
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        System.out.println("Max amount (Tabulation): " + dp[n][totalTime]);
    }
}
