// https://leetcode-cn.com/problems/path-sum-iii/

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
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        unordered_map<int, int> umap; // 值-->这个值节点的个数
        umap[0] = 1; // 什么node都不加的时候
        function<int(TreeNode*, int)> dfs;
        dfs = [&](TreeNode* node, int pre_sum) -> int {
            if(!node) return 0;
            pre_sum += node->val;
            int ret = umap[pre_sum - targetSum];
            umap[pre_sum]++;
            ret += dfs(node->left, pre_sum) + dfs(node->right, pre_sum);
            umap[pre_sum]--;
            return ret;
        };
        return dfs(root, 0);
    }
};