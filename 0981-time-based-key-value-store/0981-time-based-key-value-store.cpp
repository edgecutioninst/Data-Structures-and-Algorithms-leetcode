class TimeMap {
public:
    TimeMap() {}

    unordered_map<string, vector<pair<int,string>>> m;

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int low = 0, high = m[key].size() - 1; // index 
        string ans = "";
        while( low <= high )
        {
            int mid = (low + high)/2;

            if (m[key][mid].first <= timestamp)
            {
                ans = m[key][mid].second;
                low = mid + 1 ;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
**/