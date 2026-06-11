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

    void preorder(TreeNode* root, int maxi, int &count)
    {
        if(!root) return;

        if(root->val >= maxi)
        {
            count += 1;
            maxi = max(root->val, maxi);
        }

        preorder(root->left, maxi, count);
        preorder(root->right, maxi, count);
    }

    int goodNodes(TreeNode* root) {
        // PreOrder traversal, accept if val >= current maximum

        int maxi = INT_MIN;
        int count = 0;
        preorder(root,maxi, count);
        return count;
    }
};