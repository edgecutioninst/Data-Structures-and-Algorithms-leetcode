class Solution {
public:

    int recurse(vector<int>& coins, int amount, vector<int>&dp)
    {
        if(amount == 0) return 0;

        if(amount < 0) return INT_MAX;

        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;

        for(int i = 0; i<coins.size(); i++)
        {
            int _ = recurse(coins, amount - coins[i], dp);

            if (_ != INT_MAX) 
            ans = min(1 + _, ans);
        }
        return dp[amount] = ans;
    }


    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1); 

        int ans = recurse(coins, amount, dp);

        return (ans!=INT_MAX) ? ans : -1;
    }
};