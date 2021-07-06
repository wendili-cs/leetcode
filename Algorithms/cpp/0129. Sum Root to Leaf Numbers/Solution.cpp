// https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode* root) {
        function<long(TreeNode*, long)> recur;
        recur = [&](TreeNode* node, long num) -> long {
            if(!node->left && !node->right) return num*10 + node->val;
            long ret = 0;
            if(node->left) ret += recur(node->left, num*10 + node->val);
            if(node->right) ret += recur(node->right, num*10 + node->val);
            return ret;
        };
        return recur(root, 0);
    }
};