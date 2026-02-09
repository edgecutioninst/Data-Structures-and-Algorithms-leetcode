class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited, stack<int>& st) 
    {
        visited[node] = 1;
        pathVisited[node] = 1; // marked currently in recursion stack
        
        for(int i = 0; i < adj[node].size(); i++) 
        {
            int neighbor = adj[node][i];
            
            if(!visited[neighbor]) 
            {
                if(dfs(neighbor, adj, visited, pathVisited, st)) return true; // cycle found deeper, return back 1
            }

            //cycle found
            else if(pathVisited[neighbor]) 
            return true;
        }
        
        pathVisited[node] = 0;
        
        //push on the way back and backtrack the path aswelll
        st.push(node);
        
        return false; 
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) 
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u); // prereq -> course
        }
        
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        stack<int> st;
        
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                //if (true) -> cycle -> cant be sorted
                if(dfs(i, adj, visited, pathVisited, st)) return {}; 
            }
        }
        
        //reverses the order giving the perfect sort
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};