// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

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
    int longestConsecutive(TreeNode* root) {
        int res = 1;
        function<int(TreeNode*)> recur;
        recur = [&](TreeNode* node) -> int {
            if(!node) return 0;
            int ret = 1, left = recur(node->left), right = recur(node->right);
            if(node->left && node->left->val == node->val + 1){
                ret = max(ret, left + 1);
            }
            if(node->right && node->right->val == node->val + 1){
                ret = max(ret, right + 1);
            }
            res = max(res, ret);
            return ret;
        };
        recur(root);
        return res;
    }
};