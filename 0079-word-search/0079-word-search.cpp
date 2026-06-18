class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int index)
    {
        if(index == word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(visited[i][j]) return false;
        if(board[i][j] != word[index]) return false;

        visited[i][j] = true;

        bool result = (
            dfs(board, word, visited, i+1, j, index+1) ||
            dfs(board, word, visited, i-1, j, index+1) ||
            dfs(board, word, visited, i, j+1, index+1) ||
            dfs(board, word, visited, i, j-1, index+1)
        );

        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(dfs(board, word, visited, i, j, 0)) return true;

        return false;
    }
};