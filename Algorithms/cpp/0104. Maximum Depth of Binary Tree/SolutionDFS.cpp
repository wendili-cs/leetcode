// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode* root) {
        function<int(TreeNode*)> dfs;
        dfs = [&](TreeNode* node) -> int {
            if(!node) return 0;
            int dep = dfs(node->left);
            dep = max(dep, dfs(node->right));
            return dep + 1;
        };
        return dfs(root);
    }
};