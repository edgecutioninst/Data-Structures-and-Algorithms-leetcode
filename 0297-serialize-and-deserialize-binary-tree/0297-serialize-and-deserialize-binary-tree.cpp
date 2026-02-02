/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serialHelper(TreeNode* root, string &s)
    {
        if(!root) 
        {
            s+="#,";
            return;
        }

        s += std::to_string(root->val) + ",";

        serialHelper(root->left,s); 
        
        serialHelper(root->right,s); 
    }

    TreeNode* deserialHelper(string &data, int &i)
    {
        if(data[i] == '#')
        {
            i += 2; //skip #,
            return NULL; 
        }

        //fetch number:
        string s = "";
        while(data[i] != ',')
        {
            s += data[i];
            i++;
        }

        i++; //skips ','

        TreeNode *node = new TreeNode(stoi(s));

        node->left = deserialHelper(data, i);
        node->right = deserialHelper(data, i);

        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string s = "";
        serialHelper(root,s);
        return s;    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {   
        int i = 0;
        return deserialHelper(data, i);    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));