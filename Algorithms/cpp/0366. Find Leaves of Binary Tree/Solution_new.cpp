// https://leetcode.com/problems/find-leaves-of-binary-tree/

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> tmp;
        function<TreeNode*(TreeNode*)> dfs;
        dfs = [&](TreeNode* node) -> TreeNode* {
            if(!node) return nullptr;
            if(!node->left && !node->right){
                // this node is leaf
                tmp.push_back(node->val);
                return nullptr;
            }
            if(node->left && !dfs(node->left)){ // left node is leaf
                node->left = nullptr;
            }
            if(node->right && !dfs(node->right)){ // right node is leaf
                node->right = nullptr;
            }
            return node;
        };
        while(root){
            root = dfs(root);
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};