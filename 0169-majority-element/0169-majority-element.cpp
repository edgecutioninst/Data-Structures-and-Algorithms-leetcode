class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maxCount = 1;
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
           
           if(maxCount == 0)
           ans = nums[i];

           if(nums[i] == ans)
           maxCount ++;

           else if (nums[i] != ans)
           maxCount --;


        }

        return ans;

    }
};