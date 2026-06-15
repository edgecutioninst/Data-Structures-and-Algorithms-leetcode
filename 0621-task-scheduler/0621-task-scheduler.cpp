class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(int i = 0; i < tasks.size(); i++)
        freq[tasks[i] - 'A']++;

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];

        int maxCount = 0;
        for(int i = 0; i < 26; i++)
        if(freq[i] == maxFreq) maxCount++;

        int result = (maxFreq - 1) * (n + 1) + maxCount;
        return max(result, (int)tasks.size());

    }
};