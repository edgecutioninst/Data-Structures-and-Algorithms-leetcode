class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        int m = grid.size(); 
        int n = grid[0].size();
        
        if(i >= m || j >= n) return 1000000000;

        if (i == m - 1 && j == n - 1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = grid[i][j] + min(
            solve(i + 1, j, dp, grid),
            solve(i, j + 1, dp, grid)
        );
    }

    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int>> dp ( 
            grid.size(),
            vector<int> (grid[0].size(),-1)
        );

        return solve(0, 0, dp, grid);
    }
};