// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        
        function<TreeNode*(int, int, int, int)> recur;
        recur = [&](int l1, int r1, int l2, int r2) -> TreeNode* {
            if(l1 > r1 || l2 > r2) return nullptr;
            TreeNode* node = new TreeNode(preorder[l1]);
            int x = mp[preorder[l1]]; // x is the index of the current root in inorder array
            int llen = x - l2, rlen = r2 - x;
            node->left = recur(l1 + 1, l1 + llen, l2, x - 1);
            node->right = recur(l1 + 1 + llen, r1, x + 1, r2);
            return node;
        };
        return recur(0, n - 1, 0, n - 1);
    }
};