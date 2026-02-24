class Solution {
public:

    int countSubsets(vector<int>& arr, int target) 
    {
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1; 

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) 
            { 
                if (arr[i - 1] <= j) 
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]);
                
                else 
                dp[i][j] = dp[i - 1][j];
            
            }
        }

        return dp[n][target];
    }


    int findTargetSumWays(vector<int>& nums, int target) 
    {

        int totalSum = 0;
        for (int x : nums) totalSum += x;

        if (totalSum < abs(target) || (totalSum + target) % 2 != 0 || (totalSum + target) < 0)
        return 0;
        

        int s1 = (totalSum + target) / 2;
        return countSubsets(nums, s1);
        
    }
};