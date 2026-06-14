class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        for(int i = 0; i < stones.size(); i++)
        pq.push(stones[i]);

        while(pq.size() > 1)
        {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            if(first == second)
            continue;

            else
            {
                int diff = abs(first - second);
                pq.push(diff);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};