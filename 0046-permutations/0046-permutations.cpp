class Solution {
public:

    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, vector<bool>& visited)
    {
        if(temp.size() == nums.size()) 
        {
           ans.push_back(temp); 
            return; 
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i]) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            solve(nums, temp, ans, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool>visited(nums.size(),0);
        solve(nums, temp, ans, visited);
        return ans;
    }
};