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
    // int solve2(vector<int>& nums, int n, vector<int> &dp)
    // {
    //     if(n == 0) return nums[0];
    //     if(n < 0) return 0;

    //     if(dp[n] != -1) return dp[n];

    //     int incl = solve2(nums, n-2, dp) + nums[n];
    //     int excl = solve2(nums, n-1, dp);

    //     return dp[n] = max(incl,excl);
    // }


    int rob(vector<int>& nums) {
        // A: Recursion
        // return solve(nums, nums.size() - 1);

        // B: Tabulate
        // vector<int>dp(nums.size()+1, -1);
        // return solve2(nums, nums.size() - 1,dp);

        // C: Bottom Up
        
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // vector<int>dp(n + 1, INT_MIN);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // use 3 variables instead since it depends on -2 and -1 only

        int prev2 = 0;  
        int prev1 = nums[0];  

        for(int i = 1; i < n; i++)
        {
            int incl = prev2 + nums[i]; 
            int excl = prev1;
            int ans = max(incl,excl);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;



    }
};