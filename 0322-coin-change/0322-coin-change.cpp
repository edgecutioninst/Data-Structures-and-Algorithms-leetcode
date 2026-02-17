class Solution {
public:

    //A: 
    // int recurse(vector<int>& coins, int amount, vector<int>&dp)
    // {
    //     if(amount == 0) return 0;

    //     if(amount < 0) return INT_MAX;

    //     if(dp[amount] != -1) return dp[amount];

    //     int mini = INT_MAX;

    //     for(int i = 0; i<coins.size(); i++)
    //     {
    //         int ans = recurse(coins, amount - coins[i], dp);

    //         if (ans != INT_MAX) 
    //         mini = min(1 + ans, mini);
            
    //     }
        
    //     return dp[amount] = mini;
    // }




    int coinChange(vector<int>& coins, int amount) {

        // vector<int> dp(amount + 1, -1); 

        // int ans = recurse(coins, amount, dp);

        // return (ans!=INT_MAX) ? ans : -1;
        // ^  A ends here ^

        // B begins here:

        vector<int> dp(amount+1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++) {
                
                if (i - coins[j] >= 0) 
                {
                    
                    if (dp[i - coins[j]] != INT_MAX) 
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return (dp[amount] != INT_MAX) ? dp[amount] : -1;
    }
};