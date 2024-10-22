// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        function<void(TreeNode*)> dfs_encode;
        dfs_encode = [&](TreeNode* node) -> void {
            if(!node) {
                s += " null"; // 空格+null
                return;
            }
            s += " " + to_string(node->val);
            dfs_encode(node->left);
            dfs_encode(node->right);
        };
        dfs_encode(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        function<TreeNode*()> dfs_decode;
        dfs_decode = [&]() -> TreeNode* {
            string str;
            if(ss >> str){
                if(str == "null") return nullptr; // 这个位置没有node
                int val = stoi(str);
                TreeNode* root = new TreeNode(val);
                root->left = dfs_decode();
                root->right = dfs_decode();
                return root;
            }
            return nullptr;
        };
        return dfs_decode();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));