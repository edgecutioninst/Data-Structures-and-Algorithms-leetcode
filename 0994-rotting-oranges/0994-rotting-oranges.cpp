class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int freshCount = 0;
                 //<row,col>
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    freshCount ++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        if(!freshCount) return 0;

        while(!q.empty() && freshCount > 0)
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if(r - 1 >= 0 && grid[r-1][c] == 1){
                    freshCount--;
                    grid[r-1][c] = 2;
                    q.push({r-1, c});
                }
                
                if(r + 1 < grid.size() && grid[r+1][c] == 1) {
                    freshCount--;
                    grid[r+1][c] = 2;
                    q.push({r+1, c});
                }
                
                if(c - 1 >= 0 && grid[r][c-1] == 1) {
                    freshCount--;
                    grid[r][c-1] = 2;
                    q.push({r, c-1});
                }
                
                if(c + 1 < grid[0].size() && grid[r][c+1] == 1) {
                    freshCount--;
                    grid[r][c+1] = 2;
                    q.push({r, c+1});
                }
            }
            time ++;
        }

        if(!freshCount) return time;

        else return -1;

    }
};