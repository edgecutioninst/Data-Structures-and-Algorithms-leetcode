class Solution {
public:

    int solve (int i, int prev_i,vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i == nums.size()) return 0;

        if(dp[i][prev_i+1] != -1) return dp[i][prev_i + 1];

        int skip = 0;
        skip = solve(i + 1, prev_i, nums, dp);

        int take = 0;
        if(prev_i == -1 || nums[i] > nums[prev_i])
        take = 1 + solve(i + 1, i, nums, dp);

        return dp[i][prev_i + 1 ] = max(take,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(
            nums.size(),
            vector<int>(nums.size() + 1, -1) //prev_i can be -1 asw
        );
        return solve(0, -1 ,nums, dp);
    }
};