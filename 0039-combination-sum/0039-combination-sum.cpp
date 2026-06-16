class Solution {
public:

    void combination (vector<int> &candidates, int x, vector<vector<int>> &ans, vector<int> &temp, int sum, int i)
    {
        if(i == candidates.size())
        {
            if(sum == x)
            {
                ans.push_back(temp);
            }
            return;
        }

        if (sum + candidates[i] <= x) 
        {
            temp.push_back(candidates[i]);
    
            combination(candidates, x, ans, temp, sum + candidates[i], i); 
            
            temp.pop_back();                 
        }

        //moves to next:
        combination(candidates, x, ans, temp, sum, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {

        vector<vector<int>> ans;
        vector<int> temp;

        int sum = 0;

        combination(candidates, target, ans, temp, sum, 0);

        return ans;

    }
};