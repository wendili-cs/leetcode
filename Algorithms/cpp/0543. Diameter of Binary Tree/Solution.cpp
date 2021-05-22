// https://leetcode-cn.com/problems/diameter-of-binary-tree/

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
    int diameterOfBinaryTree(TreeNode* root) {
        function<int(TreeNode*)> recur;
        int res = 0;
        recur = [&](TreeNode* node) -> int {
            if(!node) return 0;
            if(!node->left && !node->right) return 1;
            int llen = recur(node->left), rlen = recur(node->right);
            res = max(res, llen + rlen);
            return max(llen, rlen) + 1;
        };
        recur(root);
        return res;
    }
};