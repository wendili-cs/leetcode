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
        vector<int> temp;
        function<TreeNode*(TreeNode*)> recur;
        recur = [&](TreeNode* node) -> TreeNode* {
            if(!node->left && !node->right){
                temp.push_back(node->val);
                return nullptr;
            }
            if(node->left){
                if(!recur(node->left)) node->left = nullptr;
            }
            if(node->right){
                if(!recur(node->right)) node->right = nullptr;
            }
            return node;
        };
        while(recur(root)){
            res.push_back(temp);
            temp.clear();
        }
        if(!temp.empty()) res.push_back(temp);
        return res;
    }
};