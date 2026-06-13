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

    void serial(TreeNode* root, string &str)
    {
        if(!root)
        {
            str += "N,";
            return; 
        }

        str += to_string(root->val) + ",";

        serial(root->left,str);
        serial(root->right,str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        serial(root, str);
        return str;
    }


    
    TreeNode* deserial(vector<string>& tokens, int& i)
    {
        if(tokens[i] == "N") 
        { 
            i++; 
            return NULL; 
        }

        TreeNode* node = new TreeNode(stoi(tokens[i]));
        i++;

        node->left = deserial(tokens, i);
        node->right = deserial(tokens, i);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string token;

        for(char c : data) 
        {
            if(c == ',') 
            { 
                tokens.push_back(token); 
                token = ""; 
            }
            else token += c;
        }
        int i = 0;
        return deserial(tokens, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));