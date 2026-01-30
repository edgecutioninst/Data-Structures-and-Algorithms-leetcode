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
    void flatten(TreeNode* root) 
    {
        if(!root) return;

        TreeNode* curr = root; // holds parent

        while(curr)
        {
            if (curr->left)
            {
                //hold the left node
                TreeNode* prev = curr->left;

                //go to the rightmost from left node for tail:
                while (prev->right)
                prev = prev->right;

                //stitch tail's right to parent's right
                prev->right = curr->right;

                //move parents left child to right spot
                curr->right = curr->left;

                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};