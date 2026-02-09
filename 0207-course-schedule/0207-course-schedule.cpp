class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {   
        //adj list:
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];  // want to take
            int v = prerequisites[i][1]; //must take first

            adj[v].push_back(u); //prereq -> course
            indegree[u]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) 
        {
            if(indegree[i] == 0) 
            q.push(i);
        }

        int coursesFinished = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            coursesFinished++; // finished current course.

           for(int i = 0; i < adj[node].size(); i++) 
           {
                int neighbor = adj[node][i];

                indegree[neighbor]--;
                
                if(indegree[neighbor] == 0) 
                q.push(neighbor);
                
            }
        }

        return coursesFinished == numCourses;

    }
};