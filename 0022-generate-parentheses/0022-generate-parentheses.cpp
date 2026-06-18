class Solution {
public:

    void combination( vector<string> &ans, int n,string curr, int open, int close)
    {
        if(curr.size() == 2*n)
        {
            ans.push_back(curr);
            return;
        }

        if (open < n)
        combination(ans, n, curr + '(', open + 1, close);
        
        if (close < open) 
        combination(ans, n, curr + ')', open, close + 1);
        
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        combination(ans,n, "", 0, 0);
        return ans;

    }
};