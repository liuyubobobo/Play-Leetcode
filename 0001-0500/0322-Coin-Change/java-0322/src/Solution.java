class Solution {
    public int coinChange(int[] coins, int amount) {

        int n = coins.length;

        int[] dp = new int[amount + 1];
        for(int s = 0; s <= amount; s ++) dp[s] = Integer.MAX_VALUE / 2;
        dp[0] = 0;

        for(int i = 0; i < n; i ++)
            for(int s = coins[i]; s <= amount; s ++)
                dp[s] = Math.min(dp[s], 1 + dp[s - coins[i]]);
        return dp[amount] < Integer.MAX_VALUE / 2 ? dp[amount] : -1;
    }
}