// https://leetcode-cn.com/problems/house-robber-iii/

// 要点：递归两次（用/不用当前节点）由于会超时所以用DP
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
    int rob(TreeNode* root) {
        if(!root) return 0;
        unordered_map<TreeNode*, int> dp_t, dp_f;
        function<int(TreeNode*, bool)> recur;
        recur = [&](TreeNode* node, bool allow) -> int {
            if(!node) return 0;
            if(allow && dp_t.find(node) != dp_t.end()) return dp_t[node];
            else if(!allow && dp_f.find(node) != dp_f.end()) return dp_f[node];
            int max_s = recur(node->left, true) + recur(node->right, true);
            if(allow){
                max_s = max(recur(node->left, false) + node->val + recur(node->right, false), max_s);
            }
            allow? dp_t[node] = max_s:dp_f[node] = max_s;
            return max_s;
        };
        return recur(root, true);
    }
};