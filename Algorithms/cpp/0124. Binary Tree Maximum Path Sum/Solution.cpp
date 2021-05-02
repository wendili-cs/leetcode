// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        function<int(TreeNode*)> recurr;
        recurr = [&](TreeNode* node) -> int {
            if(node == nullptr){
                return 0;
            }
            int left_val = max(recurr(node->left), 0);
            int right_val = max(recurr(node->right), 0);
            res = max(res, left_val + node->val + right_val);
            int self_val = max(left_val, right_val) + node->val;
            return self_val;
        };
        recurr(root);
        return res;
    }
};