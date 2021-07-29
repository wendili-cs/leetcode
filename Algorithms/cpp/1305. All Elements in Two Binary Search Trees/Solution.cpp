// https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, res;
        function<void(TreeNode*, vector<int>&)> dfs;
        dfs = [&](TreeNode* node, vector<int>& v) -> void {
            if(!node) return;
            dfs(node->left, v);
            v.push_back(node->val);
            dfs(node->right, v);
        };
        dfs(root1, v1);
        dfs(root2, v2);
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));
        return res;
    }
};