class Solution {
public:

    void solve(vector<int> &nums, int i, vector<int>&temp, vector<vector<int>>&res)
    {
        if(i == nums.size())
        {
            res.push_back(temp);
            return;
        }

        //dont pick:
        solve(nums, i+1, temp, res);

        //pick:
        temp.push_back(nums[i]);
        solve(nums, i+1, temp, res);

        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        solve(nums, 0, temp, res);
        
        return res;
    }
};