class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inPath, vector<int> &result)
    {
        inPath[node] = 1; 

        for(int j = 0; j < adj[node].size(); j++) 
        {
            int neigh = adj[node][j];

            if(inPath[neigh]) return true; // cycle
            
            if(!visited[neigh])
                if(dfs(neigh, adj, visited, inPath, result)) return true;
        }

        inPath[node] = false;
        visited[node] = true;
        result.push_back(node);
        return false; // no cycle found
    } 


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) 
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inPath(numCourses, false);

        vector<int> result;

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                //if (true) -> cycle detected -> wrong
                if(dfs(i, adj, visited, inPath, result)) return {}; 
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }   
};