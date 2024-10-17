// https://leetcode-cn.com/problems/path-sum-iii/
// https://leetcode.com/problems/path-sum-iii/

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
        // 访问到一个node的时候，v2n里面存储的是这个node的上面祖先的{前缀和-这个值的祖先节点有多少个}
        // 比如一条从祖先到后辈的链：3 - 3 - 5，访问到5的时候，当前prefix sum=11
        // 我们已有：mp[3] = 1, mp[6] = 1
        // 所以如果要找targetSum=8,只用找mp[11 - 8] = mp[3] = 1
        int res = 0;
        unordered_map<long, int> mp;
        mp[0] = 1;
        function<void(TreeNode*, long)> dfs;
        dfs = [&](TreeNode* node, long prefix_sum) -> void {
            if(!node) return;
            prefix_sum += node->val;
            res += mp[prefix_sum - targetSum];
            mp[prefix_sum]++;
            dfs(node->left, prefix_sum);
            dfs(node->right, prefix_sum);
            mp[prefix_sum]--;
        };
        dfs(root, 0);
        return res;
    }
};