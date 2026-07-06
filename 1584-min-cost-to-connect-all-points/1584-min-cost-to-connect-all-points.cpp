class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        vector<bool> vis(n, false);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        int ans = 0;
                //wt, node(0 weight of node at 0th index of points array)
        pq.push({0, 0});

        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(vis[node]) continue;

            vis[node] = 1;

            ans += wt;

            for(int v = 0; v < n; v++)
            {
                if(vis[v])  continue;
                
                int wt = abs(points[node][0] - points[v][0]) +
                         abs(points[node][1] - points[v][1]);

                pq.push({wt, v});        
            }
        }

        return ans;
    }
};