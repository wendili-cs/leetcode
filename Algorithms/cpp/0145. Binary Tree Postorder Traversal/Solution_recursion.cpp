// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) return {root->val};
        vector<int> rres = postorderTraversal(root->right);
        vector<int> lres = postorderTraversal(root->left);
        vector<int> res;
        res.insert(res.end(), lres.begin(), lres.end());
        res.insert(res.end(), rres.begin(), rres.end());
        res.push_back(root->val);
        return res;
    }
};