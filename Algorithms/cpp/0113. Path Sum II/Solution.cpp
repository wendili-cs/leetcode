// https://leetcode-cn.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        function<void(TreeNode*, int)> recur;
        vector<vector<int> > res;
        vector<int> temp;
        recur = [&](TreeNode* node, int remain) -> void {
            temp.push_back(node->val);
            if(!node->left && !node->right){
                if(remain == node->val){
                    res.push_back(temp);
                }
            }
            if(node->left) recur(node->left, remain - node->val);
            if(node->right) recur(node->right, remain - node->val);
            temp.pop_back();
        };
        recur(root, targetSum);
        return res;
    }
};