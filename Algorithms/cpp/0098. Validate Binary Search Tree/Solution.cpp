// https://leetcode-cn.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, long long, long long)> recur;
        recur = [&](TreeNode* node, long long v_min, long long v_max) -> bool {
            if(!node) return true;
            if(node->val <= v_min || node->val >= v_max) return false;
            if(node->left && node->val <= node->left->val) return false;
            if(node->right && node->val >= node->right->val) return false;
            return recur(node->left, v_min, node->val) && recur(node->right, node->val, v_max);
        };
        long long MIN = -2147483649, MAX = 2147483648;
        return recur(root, MIN, MAX);
    }
};