class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> counts;

        for(int i = 0; i < nums.size(); i++)
        counts[nums[i]]++;
        
        //queueu storing freq,num (will sort automatically on basis of freq)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (unordered_map<int, int>::iterator it = counts.begin(); it != counts.end(); it++)
        {
            int num = it->first;   
            int freq = it->second; 
            
            pq.push({freq, num});
            
            if (pq.size() > k) 
            pq.pop();
    
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second); 
            pq.pop();
        }

        return result;
    }
};