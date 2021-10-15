// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};
        vector<int> res;
        function<int(TreeNode*)> dfs;
        function<void(TreeNode*, int)> add_subnode;
        dfs = [&](TreeNode* node) -> int {
            if(!node) return -1;
            if(node->val == target->val){
                add_subnode(node->left, k - 1);
                add_subnode(node->right, k - 1);
                return 0;
            }
            int l_res = dfs(node->left), r_res = dfs(node->right);
            if(l_res >= 0) {
                if(l_res == k - 1) res.push_back(node->val);
                add_subnode(node->right, k - l_res - 2);
                return l_res + 1;
            }
            else if(r_res >= 0) {
                if(r_res == k - 1) res.push_back(node->val);
                add_subnode(node->left, k - r_res - 2);
                return r_res + 1;
            }
            return -1;
        };
        add_subnode = [&](TreeNode* node, int dis) -> void {
            if(!node) return;
            if(dis <= 0){
                if(dis == 0) res.push_back(node->val);
                return;
            }
            add_subnode(node->left, dis - 1);
            add_subnode(node->right, dis - 1);
        };
        dfs(root);
        return res;
    }
};