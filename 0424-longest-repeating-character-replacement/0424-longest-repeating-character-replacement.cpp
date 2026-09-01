class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxLen = INT_MIN;
        int freq = 0; // most repeating char
        int win = 0; //window size

        unordered_map<char,int>m;

        while(r < s.size())
        {
            m[s[r]]++;

            win = r - l + 1;
        
            freq = max(freq, m[s[r]]);

            // replacement needed = total window size - frequency of most common character
            while(k < win - freq)
            {
                m[s[l]]--;
                l++;
                win = r - l + 1;
            }

            maxLen = max(maxLen, win);
            r++;
        }

        return maxLen;
    }
};