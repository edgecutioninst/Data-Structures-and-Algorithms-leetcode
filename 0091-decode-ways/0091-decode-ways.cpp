class Solution {
public:

    int solve(int i, string &s, vector<int> &dp)
    {
        if(s[i] == '0') return 0;
        if(s.size() == i) return 1;

        if(dp[i] != -1) return dp[i];

        int ways = 0;
        ways += solve(i+1, s, dp);

        if(i + 1 < s.size())
        {
            string temp = s.substr(i, 2);

            if(stoi(temp) <= 26 && stoi(temp) >= 10)
                ways += solve(i+2, s, dp);
        }

        dp[i] = ways;
        return dp[i];
    }   

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, dp);
    }
};