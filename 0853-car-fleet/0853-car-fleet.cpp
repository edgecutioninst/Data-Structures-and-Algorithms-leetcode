class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,int>> cars;

        for(int i = 0; i < position.size(); i++)
        cars.push_back({position[i], speed[i]});

        sort(cars.rbegin(), cars.rend());

        vector<double> time;

        for(int i = 0; i < speed.size(); i++)
        {
            double val = (double)(target - cars[i].first) / cars[i].second;
            time.push_back(val);
        }
        
        stack<double> st;

        for(int i = 0; i < time.size(); i++)
        {
            if(st.empty() || time[i] > st.top())
                st.push(time[i]);
        }
        return st.size();
    }
};