class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        int n = grid.size();

        pq.push({grid[0][0], 0, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        while(!pq.empty())
        {
            auto [weight, row, col] = pq.top();
            pq.pop();

            if(visited[row][col]) continue;

            visited[row][col] = true;

            if(row == n-1 && col == n-1) return weight;

            // Up
            if(row - 1 >= 0 && !visited[row-1][col])
            {
                int newWeight = max(weight, grid[row-1][col]);
                pq.push({newWeight, row-1, col});
            }

            // Down
            if(row + 1 < n && !visited[row+1][col])
            {
                int newWeight = max(weight, grid[row+1][col]);
                pq.push({newWeight, row+1, col});
            }

            // Left
            if(col - 1 >= 0 && !visited[row][col-1])
            {
                int newWeight = max(weight, grid[row][col-1]);
                pq.push({newWeight, row, col-1});
            }

            // Right
            if(col + 1 < n && !visited[row][col+1])
            {
                int newWeight = max(weight, grid[row][col+1]);
                pq.push({newWeight, row, col+1});
            }
        }

        return -1;
    }
};