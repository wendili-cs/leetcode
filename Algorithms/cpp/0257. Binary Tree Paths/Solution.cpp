// https://leetcode-cn.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        // string temp = to_string(root->val);
        function<void(TreeNode*, string)> recur;
        recur = [&](TreeNode* node, string temp) -> void {
            if(!node->left && !node->right) res.push_back(temp);
            if(node->left){
                string num = to_string(node->left->val);
                recur(node->left, temp + "->" + num);
            }
            if(node->right){
                string num = to_string(node->right->val);
                recur(node->right, temp + "->" + num);
            }
        };
        recur(root, to_string(root->val));
        return res;
    }
};