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
                combination(candidates, x, ans, temp, sum + candidates[i], i + 1); 
                temp.pop_back();                 
            }

            while (i + 1 < candidates.size() && candidates[i] == candidates[i+1]) 
            i++;
            // done to avoid duplicate answers

            combination(candidates, x, ans, temp, sum, i + 1);
        }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());


        int sum = 0;

        combination(candidates, target, ans, temp, sum, 0);

        return ans;
    }
};