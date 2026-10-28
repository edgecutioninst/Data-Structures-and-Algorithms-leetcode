class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size() - 1;
        int maxArea = INT_MIN;

        while( left < right)
        {
            int left_wall = height[left], right_wall = height[right];

            int minHeight = min(left_wall,right_wall);

            int area = (right - left) * minHeight;

            maxArea = max(maxArea, area);

            if (left_wall < right_wall) left++;
            else right--;
        }   
        return maxArea;
    }
};