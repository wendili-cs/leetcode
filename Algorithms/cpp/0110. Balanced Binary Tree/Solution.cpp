// https://leetcode-cn.com/problems/balanced-binary-tree/

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
    int calcHeight(TreeNode* node) {
        if(!node) return 0;
        return max(calcHeight(node->left), calcHeight(node->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(calcHeight(root->left) - calcHeight(root->right)) > 1) return false;
        if(!isBalanced(root->left)||!isBalanced(root->right)) return false;
        return true;
    }
};