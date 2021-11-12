// https://leetcode.com/problems/maximum-average-subtree/

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
    double res = 0.0;
    double maximumAverageSubtree(TreeNode* root) {
        function<vector<int>(TreeNode*)> recur;
        recur = [&](TreeNode* node) -> vector<int>{
            if(!node) return {0, 0};
            vector<int> left = recur(node->left), right = recur(node->right);
            res = max(((double)left[1] + right[1] + node->val)/(left[0] + right[0] + 1), res);
            return {left[0] + right[0] + 1, left[1] + right[1] + node->val};
        };
        recur(root);
        return res;
    }
};