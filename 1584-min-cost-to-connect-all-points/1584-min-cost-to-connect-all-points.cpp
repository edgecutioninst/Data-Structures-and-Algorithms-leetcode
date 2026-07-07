class Solution {
public:

    int find(vector<int>& parent, int x) 
    {
        while(parent[x] != x) 
        {
            x = parent[x];
        }
        return x;
    }


    bool unite(vector<int>& parent, vector<int>& rank, int x, int y) 
    {
        int px = find(parent, x), py = find(parent, y);
        if(px == py) return false; // cycle

        if(rank[px] > rank[py]) 
        parent[py] = px;

        else if(rank[px] < rank[py]) 
        parent[px] = py;

        else 
        { 
            parent[py] = px; 
            rank[px]++; 
        }

        return true;    
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();

        vector<vector<int>> edges;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);
                edges.push_back({wt, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++)
        parent[i] = i;

        int ans = 0;

        for(int i = 0; i < edges.size(); i++)
        {
            int wt = edges[i][0];
            int u  = edges[i][1];
            int v  = edges[i][2];

            if(unite(parent, rank, u, v))
            ans += wt;
        }
        return ans;
    }
};