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
    vector<int> preorderTraversal(TreeNode* root) {
         vector <int> ans;
        TreeNode* curr = root;

        while(curr)
        {
            if (!curr->left) 
            {   
                // no left child, we push and go right.
                ans.push_back(curr->val);
                curr = curr->right;
            }

            else
            {   
                //left found, go to rightmost tail
                TreeNode* prev = curr->left;


                //reach tail:
                while (prev->right && prev->right != curr)
                prev = prev->right;

                //reached end, make link to parent;
                if (!prev->right)
                {
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }

                else
                {  // break link
                    prev->right = NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};