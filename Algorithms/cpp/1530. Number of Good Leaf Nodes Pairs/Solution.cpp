// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

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
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        function<vector<int>(TreeNode*)> recur;
        recur = [&](TreeNode* node) -> vector<int> { // return the distances for all leaf nodes
            if(!node) return {};
            if(!node->left && !node->right) return {1};
            vector<int> l,r,ret;
            l = recur(node->left);
            r = recur(node->right);
            for(int eachl:l){
                for(int eachr:r){
                    if(eachl + eachr <= distance) res++;
                }
                ret.push_back(eachl + 1);
            }
            for(int eachr:r){
                ret.push_back(eachr + 1);
            }
            return ret;
        };
        recur(root);
        return res;
    }
};