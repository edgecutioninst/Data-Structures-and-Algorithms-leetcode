class Solution {
public:

    void dfs(int row, int col, vector<vector<char>> &grid , vector<vector<int>> &vis) 
    {
        int n = grid.size();
        int m = grid[0].size();

        if (
            row < 0 || col < 0 || row >= n || col >= m 
            || grid[row][col] == '0' || vis[row][col] == 1
        )   return;

        vis[row][col] = 1;

        dfs(row - 1, col, grid, vis); 
        dfs(row + 1, col, grid, vis); 
        dfs(row, col - 1, grid, vis); 
        dfs(row, col + 1, grid, vis); 
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0)); 
        int count = 0;

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(!visited[row][col] && grid[row][col] == '1') 
                {
                    count++; 
                    dfs(row, col, grid, visited); 
                }
            }
        }

        return count;
    }
};