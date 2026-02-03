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

    stack<TreeNode*> nextSt, beforeSt;

    void pushLeft(TreeNode* root) 
    {
        while (root) 
        {
            nextSt.push(root);
            root = root->left;
        }
    }
    void pushRight(TreeNode* root) 
    {
        while (root) 
        {
            beforeSt.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) 
    {

        pushLeft(root);  // Fills stack with smallest values
        pushRight(root); // ^^^^^^^^^^^^ largest values 

        TreeNode* leftNode = nextSt.top();
        TreeNode* rightNode = beforeSt.top();

        while (leftNode != rightNode)
        {
            int sum = leftNode->val + rightNode->val;
            
            if (sum == k) return true;

            if (sum < k)
            {
                nextSt.pop();
                pushLeft(leftNode->right);
                leftNode = nextSt.top();
            }
            else 
            {
                beforeSt.pop();
                pushRight(rightNode->left);
                rightNode = beforeSt.top();
            }
        }

        return false;

    }
};