/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {        
        if(!root) return 0;

        int width = INT_MIN;

        queue<pair<TreeNode*, long>> q;

        q.push({root, 0});

        while(!q.empty())
        {
            int size = q.size();
            long min0 = q.front().second; //min-knot to minus from others: prevents INT_OF
            int first, last;

            for(int i=0; i<size; i++)
            {
                long curr_index = q.front().second - min0;

                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = curr_index;
                if(i == size - 1) last = curr_index;

                if(node->left)  q.push({node->left, curr_index * 2 + 1});
                if(node->right) q.push({node->right, curr_index * 2 + 2});
            }

            width = max(width, last - first + 1);
        }

        return width;

    }
};