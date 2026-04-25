class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans; 

        // Horizontal Distance -> List of {Vertical Level, NodeValue}
        map<int, vector<pair<int, int>>> m;
        
        // Queue: {Node pointer, {Horizontal Distance, Vertical Level}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) 
        {
            auto current = q.front();
            q.pop();
            
            TreeNode* node = current.first;
            int hd = current.second.first;
            int lvl = current.second.second;
            
            m[hd].push_back({lvl, node->val});
            
            if (node->left)
            q.push({node->left, {hd - 1, lvl + 1}});
    
            if (node->right) 
            q.push({node->right, {hd + 1, lvl + 1}});    
        }
        
        for (auto& bucket : m) {
            //sort the bucket
            sort(bucket.second.begin(), bucket.second.end());
            
            vector<int> col;
            for (auto& pair : bucket.second) {
                col.push_back(pair.second);
            }
            
            ans.push_back(col);
        }
        
        return ans;
    }
};