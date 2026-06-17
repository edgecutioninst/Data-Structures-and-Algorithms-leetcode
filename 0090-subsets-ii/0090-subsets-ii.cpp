class Solution {
public:

    void subsets(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int i)
    {
        if(i == nums.size())
        {
            ans.push_back(temp);
            return;
        }


        temp.push_back(nums[i]);
    
        subsets(nums, ans, temp, i+1); 
            
        temp.pop_back();   

        while (i + 1 < nums.size() && nums[i] == nums[i+1]) 
        i++; 

        //dont pick
        subsets(nums, ans, temp, i+1);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        subsets(nums, ans, temp, 0);

        return ans;

    }
};