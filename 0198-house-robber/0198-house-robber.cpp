class Solution {
public:

    // A. RECURSION: 
    // int solve(vector<int>& nums, int n)
    // {
    //     if(n == 0) return nums[0];
    //     if(n < 0) return 0;

    //     int incl = solve(nums, n-2) + nums[n];
    //     int excl = solve(nums, n-1);

    //     return max(incl,excl);
    // }


    // B. TABULATE: 
    int solve2(vector<int>& nums, int n, vector<int> &dp)
    {
        if(n == 0) return nums[0];
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int incl = solve2(nums, n-2, dp) + nums[n];
        int excl = solve2(nums, n-1, dp);

        return dp[n] = max(incl,excl);
    }


    int rob(vector<int>& nums) {
        // A: Recursion
        // return solve(nums, nums.size() - 1);

        // B: Tabulate
        vector<int>dp(nums.size()+1, -1);
        return solve2(nums, nums.size() - 1,dp);


    }
};