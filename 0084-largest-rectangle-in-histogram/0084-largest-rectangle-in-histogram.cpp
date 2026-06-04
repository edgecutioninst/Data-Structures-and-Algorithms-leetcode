class Solution {
public:
    vector<int> nextSmallerIndex(vector<int>& arr, int n)
    {
        vector<int> next(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];

            while (!s.empty() && arr[s.top()] >= curr) 
            s.pop();

            if (s.empty()) 
            next[i] = n; 
            else 
            next[i] = s.top();
        
            s.push(i);
        }   
        return next;
    }

    vector<int> prevSmallerIndex(vector<int>& arr, int n)
    {
        vector<int> prev(n);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];

            while (!s.empty() && arr[s.top()] >= curr) 
            s.pop();

            if (s.empty()) 
            prev[i] = -1; 
            else 
            prev[i] = s.top();
        
            s.push(i);
        }   
        return prev;
    }

    int largestRectangleArea(vector<int>& heights) 
    {

        vector<int> next;
        vector<int> prev;

        next = nextSmallerIndex(heights, heights.size());
        prev = prevSmallerIndex(heights, heights.size());

        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++)  
        {
            int length = heights[i];
            int breadth = next[i] - prev[i] - 1;

            int newMaxArea = length * breadth;

            maxArea = max(newMaxArea,maxArea);
        }

        return maxArea;

    }
};