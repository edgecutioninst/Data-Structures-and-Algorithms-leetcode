class Solution {
public:
    int trap(vector<int>& height) 
    {
        vector <int> maxR(height.size());    
        vector <int> maxL;  
        int water = 0;

        int maxHeight = INT_MIN;

        for(int i = 0; i < height.size(); i++)
        {
            maxHeight = max(height[i],maxHeight);
            maxL.push_back(maxHeight);
        }

        maxHeight = INT_MIN;

        for(int i = height.size() - 1; i >= 0 ; i--)
        {
            maxHeight = max(height[i],maxHeight);
            maxR[i] = maxHeight;
        }

        for(int i = 0; i < height.size(); i++)
        {
            height[i] = min(maxL[i], maxR[i]) - height[i];
            water += height[i];
        }
        return water;
    }
};