// https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        function<void(TreeNode*)> recur;
        recur = [&](TreeNode* node) -> void {
            if(!node) return;
            if(node->left) recur(node->left);
            if(node->right) recur(node->right);
            swap(node->left, node->right);
        };
        recur(root);
        return root;
    }
};