// https://leetcode-cn.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root) {
        function<void(TreeNode*)> recurr;
        recurr = [&](TreeNode* node){
            if(!node) return;
            TreeNode *temp = node->right;
            node->right = node->left;
            node->left = temp;
            recurr(node->left);
            recurr(node->right);
            return;
        };
        recurr(root);
        return root;
    }
};