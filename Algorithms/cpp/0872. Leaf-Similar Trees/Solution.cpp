// https://leetcode-cn.com/problems/leaf-similar-trees/

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        function<string(TreeNode*)> get_leaves;
        get_leaves = [&](TreeNode* node) -> string{
            if(!node) return "";
            if(!node->left && !node->right) return "|" + to_string(+node->val);
            return (node->left?get_leaves(node->left):"") + (node->right?get_leaves(node->right):"");
        };
        return get_leaves(root1) == get_leaves(root2);
    }
};