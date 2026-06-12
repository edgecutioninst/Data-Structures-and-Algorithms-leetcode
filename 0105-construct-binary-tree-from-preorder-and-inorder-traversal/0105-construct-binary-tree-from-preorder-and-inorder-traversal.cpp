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

    TreeNode* build(vector<int>& pre, int preStart, int preEnd, vector<int>& in, int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(pre[preStart]);

        int mid = inStart;
        while(in[mid] != pre[preStart]) mid++;

        int leftSize = mid - inStart; // left subtree nodes

        root->left = build(pre, preStart+1, preStart+leftSize, in, inStart, mid-1);
        root->right = build(pre, preStart+leftSize+1, preEnd, in, mid+1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};