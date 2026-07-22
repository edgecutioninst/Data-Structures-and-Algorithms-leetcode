class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int start = 0, end = 0;
        
        unordered_map<char,bool> m;

        int maxSize = 0;

        while(end < s.size() && start < s.size())
        {
            m[s[end]] = true;

            int size = end - start + 1;
            maxSize = max(maxSize, size);

            end++;

            while(m.find(s[end]) != m.end())
            {
                m.erase(s[start]);
                start ++;
            }

        }
        return maxSize;
    }
};