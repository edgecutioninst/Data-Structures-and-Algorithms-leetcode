class Solution {
public:

    bool dfs(int node, vector<vector<int>> &adj,vector<bool> &visited, vector<bool> &inPath)
    {
        inPath[node] = true;

        for(int j = 0; j < adj[node].size(); j++) 
        {
            int neigh = adj[node][j];

            if(inPath[neigh]) return true; // cycle
            
            if(!visited[neigh])
                if(dfs(neigh, adj, visited, inPath)) return true;
        }

        inPath[node] = false;
        visited[node] = true;
        return false; // no cycle found
        }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];  // course
            int v = prerequisites[i][1]; //pre req

            adj[v].push_back(u); //prereq -> course
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inPath(numCourses, false);

        for(int i = 0; i < numCourses; i++)
            if(!visited[i])
                if(dfs(i, adj, visited, inPath)) return false;

        return true;

    }       
};