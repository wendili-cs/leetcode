// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode*>(int, int)> recur;
        recur = [&](int l, int r) -> vector<TreeNode*> {
            vector<TreeNode*> ret;
            if(l > r){
                ret.push_back(nullptr);
                return ret;
            }
            for(int i = l; i <= r; i++){
                auto left_nodes = recur(l, i - 1);
                auto right_nodes = recur(i + 1, r);
                for(auto l_node:left_nodes){
                    for(auto r_node:right_nodes){
                        TreeNode* node = new TreeNode(i);
                        node->left = l_node;
                        node->right = r_node;
                        ret.push_back(node);
                    }
                }
            }
            return ret;
        };
        return recur(1, n);
    }
};