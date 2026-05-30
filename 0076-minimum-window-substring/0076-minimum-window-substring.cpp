class Solution {
public:
    string minWindow(string s, string t) {
    if(s.empty() || t.empty() || s.size() < t.size()) return "";

    vector<int> m1(128,0), m2(128,0);

    
    for(char c : t) m1[c]++;
    
    int count = t.size(); 
    int l = 0, minLen = INT_MAX, minStart = 0;

    for(int r = 0; r < s.size(); r++)
    {
        m2[s[r]]++; 
        
        if(m2[s[r]] <= m1[s[r]]) count--;

        while(count == 0) 
        {
            if(r - l + 1 < minLen) {
                minLen = r - l + 1;
                minStart = l;
            }

            m2[s[l]]--; 
            
            if(m2[s[l]] < m1[s[l]]) count++;
            
            l++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}
};