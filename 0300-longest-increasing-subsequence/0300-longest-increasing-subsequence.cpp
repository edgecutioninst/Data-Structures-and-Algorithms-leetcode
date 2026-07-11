class Solution {
public:

    int solve (int i, int prevIndex,vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i == nums.size()) return 0;

        if(dp[i][prevIndex+1] != -1) return dp[i][prevIndex + 1];

        int skip = 0;
        skip = solve(i + 1, prevIndex, nums, dp);

        int take = 0;
        if(prevIndex == -1 || nums[i] > nums[prevIndex])
        take = 1 + solve(i + 1, i, nums, dp);

        return dp[i][prevIndex + 1 ] = max(take,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>> dp(
            nums.size(),
            vector<int>(nums.size() + 1, -1) // prev index can also take -1 too
        );

        return solve(0, -1 ,nums, dp);
    }
};