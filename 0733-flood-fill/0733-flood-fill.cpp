class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor){
        if(r < 0 || r >= image.size()) return;
        if(c < 0 || c >= image[0].size()) return;

        if(image[r][c] != originalColor) return; 

        image[r][c] = newColor;

        dfs(image, r - 1, c, originalColor, newColor); // UP
        dfs(image, r + 1, c, originalColor, newColor); // DOWN
        dfs(image, r, c - 1, originalColor, newColor); // LEFT
        dfs(image, r, c + 1, originalColor, newColor); // RIGHT
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;

        dfs(image,sr,sc, originalColor, color);
        return image;
    }
};