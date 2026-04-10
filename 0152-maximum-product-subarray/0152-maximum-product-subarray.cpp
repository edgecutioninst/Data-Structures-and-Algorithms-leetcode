class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {   
        int n = nums.size();

        double pref = 1;
        double suff = 1;
        double ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            
            if (pref == 0) pref = 1;
            if (suff == 0) suff = 1;

            pref = pref * nums[i];                 //  Left to Right
            suff = suff * nums[n - 1 - i];         //  Right to Left

            ans = max({ans, pref, suff});
        }

        return ans;
    }
};