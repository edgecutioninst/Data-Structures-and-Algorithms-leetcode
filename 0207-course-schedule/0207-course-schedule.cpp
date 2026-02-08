class Solution {
public:

    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(int i = 0; i < adj[node].size(); i++) 
        {
            int neighbor = adj[node][i];

            if(!visited[neighbor])
            {if(dfsCheck(neighbor, adj, visited, pathVisited)) return true;}

            //cycle" (visited and inside current path)            
            else if(pathVisited[neighbor]) {
                return true;
            }
        }

        pathVisited[node] = 0; //backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {   
        //adj list:
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];  // want to take
            int v = prerequisites[i][1]; //must take first

            adj[v].push_back(u); //prereq -> course
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0); // tracks recursion stack

        for(int i = 0; i < numCourses; i++) 
        {
            if(!visited[i]) 
            {
                //cycle is found
                if(dfsCheck(i, adj, visited, pathVisited)) return false; 
            }
        }
        
        return true;


    }
};