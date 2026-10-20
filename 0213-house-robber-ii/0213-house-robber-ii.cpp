class Solution {
public:

    int solve(int i, int n, vector<int> &dp, vector<int> &nums)
    {
        if( i >= n ) return 0;

        if(dp[i] != -1) return dp[i]; // returns memoised data

        // if not memoised, create one
        // rob
        int rob = 0;
        rob = nums[i] + solve(i + 2, n, dp, nums);

        // dont rob
        int skip = 0;
        skip = solve(i + 1, n, dp, nums);

        dp[i] = max(rob, skip);
        return dp[i];
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];

        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);

        return max(
            solve(0, nums.size() - 1, dp1, nums),
            solve(1, nums.size(), dp2, nums)
        );

    }
};