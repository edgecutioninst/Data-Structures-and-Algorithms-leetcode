class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor)
    {
        //grid boundary
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size())
        return;

        //some other color we cant overwrite it 
        if (image[r][c] != oldColor) 
        return;
        
        //color oldcolor to new: 
        image[r][c] = newColor;

        dfs(image, r + 1, c, oldColor, newColor); // down
        dfs(image, r - 1, c, oldColor, newColor); // up
        dfs(image, r, c + 1, oldColor, newColor); // right
        dfs(image, r, c - 1, oldColor, newColor); // lleft
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        //what if the new paint is same as old
        if (oldColor == color) return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};