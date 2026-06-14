class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> pq;


        for(int i = 0; i < points.size(); i++)
        pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i}); //x2 + y2

        while(pq.size() > k) pq.pop();

        while(!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(points[idx]);
        }
        return ans;
    }
};