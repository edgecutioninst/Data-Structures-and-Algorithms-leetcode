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


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> parent(edges.size() + 1);

        for(int i = 0; i < edges.size(); i++)
        parent[i] = i;

        vector<int> rank(edges.size() + 1, 1);

        for(int i = 0; i < edges.size(); i++)
            if(!unite(parent, rank, edges[i][0], edges[i][1]))
                return edges[i];

        return {};
    }
};