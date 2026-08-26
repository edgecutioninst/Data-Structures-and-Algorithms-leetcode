class Solution {
public:
    bool canJump(vector<int>& nums) {

        int farthest = nums[0];

        for(int i = 0; i < nums.size(); i++)
        {
            if(farthest >= nums.size() - 1) return true;

            if(i > farthest) return false;

            int dist = i + nums[i];
            farthest = max(dist, farthest);
        }
        return true;
    }
};