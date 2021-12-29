// https://leetcode.com/problems/largest-bst-subtree/

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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        function<vector<int>(TreeNode*)> recur;
        recur = [&](TreeNode* node) -> vector<int> {
            // return format {number_of_available_nodes, max_val, min_val}
            if(!node) return {0, INT_MIN, INT_MAX};
            auto left = recur(node->left), right = recur(node->right);
            if(left[0] < 0 || right[0] < 0) return {-1, INT_MIN, INT_MAX};
            if((left[0] > 0 && left[1] >= node->val)||(right[0] > 0 && right[2] <= node->val)) return {-1, INT_MIN, INT_MAX};
            res = max(res, left[0] + right[0] + 1);
            return {left[0] + right[0] + 1, max(node->val, right[1]), min(node->val, left[2])};
        };
        recur(root);
        return res;
    }
};