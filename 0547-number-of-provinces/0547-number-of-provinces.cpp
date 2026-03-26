class Solution {
public:

    void dfs(int current, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[current] = 1;

        for(int i = 0; i < isConnected[current].size();i++)
        {
            if(isConnected[current][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited); 
            }
        }

    }    

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size());
        int province = 0;

        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                province++;
            }
        }    

        return province;
    }
};