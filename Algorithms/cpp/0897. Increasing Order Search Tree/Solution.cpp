// https://leetcode-cn.com/problems/increasing-order-search-tree/

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
    TreeNode* recur(TreeNode* root, TreeNode* tail){
        if(!root) return nullptr;
        TreeNode* right = recur(root->right, tail);
        if(!right) right = tail;
        TreeNode* left = recur(root->left, root);
        if(!left) left = root;
        root->left = nullptr;
        root->right = right;
        return left;
    }

    TreeNode* increasingBST(TreeNode* root) {
        return recur(root, nullptr);
    }
};