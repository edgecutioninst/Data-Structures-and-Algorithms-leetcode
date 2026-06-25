class Solution {
public:

    void dfs(int row, int col, vector<vector<int>> &grid , vector<vector<int>> &vis, int &area) 
    {
        int n = grid.size();
        int m = grid[0].size();

        if (
            row < 0 || col < 0 || row >= n || col >= m 
            || grid[row][col] == 0 || vis[row][col] == 1
        )   return;

        vis[row][col] = 1;
        area ++;

        dfs(row - 1, col, grid, vis, area); 
        dfs(row + 1, col, grid, vis, area); 
        dfs(row, col - 1, grid, vis, area); 
        dfs(row, col + 1, grid, vis, area); 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0)); 
        int maxArea = 0;

        int area = 0;
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(!visited[row][col] && grid[row][col] == 1) 
                {
                    dfs(row, col, grid, visited, area); 
                    maxArea = max(maxArea, area);
                    area = 0;
                }
            }
        }

        return maxArea;

    }
};