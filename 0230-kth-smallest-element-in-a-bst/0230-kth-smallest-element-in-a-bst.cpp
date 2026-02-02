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

    void inorder(TreeNode* root, int k,int &result, int &count) 
    {
        if (!root || result != -1) return; //saves further recursions 

        inorder(root->left, k, result, count);

        count++;
        if (count == k) 
        {
            result = root->val;
            return; 
        }

        inorder(root->right, k, result, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        int count = 0;

        inorder(root, k, result, count);
        return result;

    }
};