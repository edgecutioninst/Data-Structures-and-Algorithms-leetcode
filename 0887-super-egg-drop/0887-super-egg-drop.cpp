class Solution {
public:

    vector<vector<int>> dp = vector<vector<int>>(101, vector<int>(10001, -1));

    int solve(int e, int f)
    {
        if( f == 0 || f == 1) return f;
        if(e == 1) return f;

        if(dp[e][f] != -1) return dp[e][f];

        int mn = INT_MAX;
        
        int l = 1, r = f;
        while (l <= r) 
        {
            int mid = l + (r - l) / 2;
            
            int left = solve(e - 1, mid - 1); // Egg breaks
            int right = solve(e, f - mid);    // Egg survives
            
            int temp = 1 + max(left, right);
            mn = min(mn, temp);
            
            if (left < right) 
            l = mid + 1; 
            else 
            r = mid - 1;
            
        }
        return dp[e][f] = mn;

    }

    int superEggDrop(int k, int n) {
        return solve(k,n);
    }
};