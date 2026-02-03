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
    
    int myMaxSum = 0;

    vector<int> helper(TreeNode* root)
    {
        //leaf nodes:    //minval,maxval,size
        if(!root) return {INT_MAX, INT_MIN, 0};

        vector<int> leftResult = helper(root->left);
        vector<int> rightResult = helper(root->right);

        //extract values:
        int leftMin = leftResult[0];
        int leftMax = leftResult[1];
        int leftSum = leftResult[2];

        int rightMin = rightResult[0];
        int rightMax = rightResult[1];
        int rightSum = rightResult[2];

        //isBST:
        if (root->val > leftMax && root->val < rightMin)
        {
            int currSum = leftSum + rightSum + root->val;
            
            myMaxSum = max(myMaxSum, currSum);

            int currMin = min(root->val, leftMin);
            int currMax = max(root->val, rightMax);

            return {currMin, currMax, currSum};
        }
        
        //make sure parent wont claim isBST: 
        return {INT_MIN, INT_MAX, 0}; 
    }

    int maxSumBST(TreeNode* root) 
    {   
        helper(root);
        return myMaxSum;    
    }
};