// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        function<pair<TreeNode*, int>(TreeNode*)> recur;
        recur = [&](TreeNode* node) -> pair<TreeNode*, int> {
            if(!node) return make_pair(nullptr, 0);
            auto left = recur(node->left), right = recur(node->right);
            if(left.second > right.second){
                return make_pair(left.first, left.second + 1);
            }
            else if(left.second < right.second){
                return make_pair(right.first, right.second + 1);
            }
            return make_pair(node, left.second + 1);
        };
        
        return recur(root).first;
    }
};