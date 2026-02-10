class Solution {
public:

    bool check(int node, int col, vector<int>& color, vector<vector<int>>& adj) 
    {
        color[node] = col; 

        for (int i = 0; i < adj[node].size(); i++) 
        {
            int neighbor = adj[node][i];

            if (color[neighbor] == -1) 
            {
                if (check(neighbor, !col, color, adj) == false) return false;
            }
            else if (color[neighbor] == col) 
            return false;
            
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        //already adj list
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) 
        {
            if (color[i] == -1) {
                //color fisrt component as 0
                if (!check(i, 0, color, graph)) return false;
            }
        }

        return true;
    }
};