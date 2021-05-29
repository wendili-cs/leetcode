// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr) return false;
        function<bool(TreeNode*, TreeNode*)> recur;
        recur = [&](TreeNode* a, TreeNode* b) -> bool {
            if(b == nullptr) return true;
            else if(a == nullptr || a->val != b->val) return false;
            return recur(a->left, b->left) && recur(a->right, b->right);
        };
        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};