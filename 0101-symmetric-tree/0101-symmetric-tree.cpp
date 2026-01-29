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

    bool isMirror(TreeNode* leftSide, TreeNode* rightSide)
    {   
        //end of tree: everything matched if we made it here
        if (!leftSide && !rightSide) return true;

        //one null -> anomaly
        if (!leftSide || !rightSide) return false;

        if (leftSide->val != rightSide->val) return false;

        return isMirror(leftSide->left, rightSide->right) && isMirror(leftSide->right, rightSide->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return isMirror(root->left, root->right);
    }
};