class Solution {
public:

    int solve(int i, int sum, vector<int>&nums, int &target, unordered_map<string, int> &dp)
    {
        if(i == nums.size())
            return (sum == target);

        string key = to_string(i) + "," + to_string(sum);

        if(dp.find(key) != dp.end()) return dp[key];

        return dp[key] = 
            solve(i + 1, sum + nums[i], nums, target, dp) +
            solve(i + 1, sum - nums[i], nums, target, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;

        return solve(0, 0, nums, target, dp);   
    }
};