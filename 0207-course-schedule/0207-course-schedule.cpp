class Solution {
public:

    bool dfs(int node, vector<vector<int>> &adj,vector<bool> &visited, vector<bool> &inPath)
    {
        inPath[node] = true;

        for(int j = 0; j < adj[node].size(); j++)
        {
            int neigh = adj[node][j];

            if(inPath[neigh] == true) return true; //cycle

            if(!visited[neigh])
                if(dfs(neigh, adj, visited, inPath)) return true;
        }

        inPath[node] = false;
        visited[node] = true;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector<bool> visited(numCourses, 0);
        vector<bool> inPath(numCourses, false);


        for(int i = 0; i < numCourses; i++)
            if(!visited[i])
                if(dfs(i, adj, visited, inPath)) return false;

        return true;



    }
};