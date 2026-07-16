class Solution {
public:

    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1)  return dp[i][j];

        int ans = 1;

        //explore in all four
        if(i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
        {
            ans = max(ans, 1 + solve(i - 1, j, matrix, dp));
        }

        if(i + 1 < matrix.size() && matrix[i + 1][j] > matrix[i][j])
        {
            ans = max(ans, 1 + solve(i + 1, j, matrix, dp));
        }    

        if(j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
        {
            ans = max(ans, 1 + solve(i, j - 1, matrix, dp));
        }

        if(j + 1 < matrix[0].size() && matrix[i][j + 1] > matrix[i][j])
        {
            ans = max(ans, 1 + solve(i, j + 1, matrix, dp));
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(
            matrix.size(),
            vector<int>(matrix[0].size(), -1)
        );
        int maxAns = 1;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j< matrix[0].size(); j++)
                maxAns = max(maxAns, solve(i,j, matrix, dp));
        return maxAns;
    }
};