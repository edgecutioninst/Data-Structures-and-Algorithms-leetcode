class Solution {
public:

    int solve(int i, bool canBuy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if( i >= prices.size()) return 0;

        if(dp[i][canBuy] != -1) return dp[i][canBuy];

        int buy = 0, skip = 0, sell = 0, hold = 0;
        if(canBuy)
        {
            buy = -prices[i] + solve(i + 1, false, prices, dp);
            skip = solve(i + 1, true, prices, dp);
            return dp[i][canBuy] = max(buy, skip);
        }
        else
        {
            sell = prices[i] + solve(i + 2, true, prices, dp);
            hold = solve(i + 1, false, prices, dp); 
            return dp[i][canBuy] = max(sell, hold);
        } return 0;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(
            prices.size(),
            vector<int>(2, -1)
        );

        return solve(0, true, prices, dp);
    }
};