class Solution {
public:

    int solve(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if(i == nums.size())
        {
            if(target == 0) return 1;
            else return 0;
        }
    
        if(dp[i][target] != -1) return dp[i][target];

        int take = 0;
        if (nums[i] <= target)
        take = solve(i + 1, nums, target - nums[i], dp);

        int skip = solve(i + 1, nums, target, dp);

        return dp[i][target] = take + skip;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;

        for (int x : nums) total += x;

        if (abs(target) > total) return 0;

        if ((total + target) % 2 != 0) return 0;

        int required = (total + target) / 2;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(required + 1, -1)
        );

        return solve(0, nums, required, dp);
    }
};