class Solution {
public:

    bool canShip(int capacity, int target_days, vector<int> &weights)
    {
        int days_needed = 1;
        int current_load = 0;

        for (int i = 0; i < weights.size(); i++) 
        {
            if (current_load + weights[i] > capacity) 
            {
                days_needed++;
                current_load = weights[i];
            } 
            else 
            {
                current_load += weights[i]; 
            }
        }
        return days_needed <= target_days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0;

        int ans = INT_MAX;
        for(int i = 0; i < weights.size(); i++)
        {
            low = max(low, weights[i]);
            high += weights[i];
        }

        while(low <= high)
        {
            int mid = (low + high)/2;

            if(canShip(mid,days, weights))
            {
                ans = min(ans,mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};