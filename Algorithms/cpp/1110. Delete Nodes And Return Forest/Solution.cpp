// https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> deletes(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        function<TreeNode*(TreeNode*)> recur;
        recur = [&](TreeNode* node) -> TreeNode* {
            if(!node) return nullptr;
            TreeNode *l, *r;
            l = recur(node->left);
            r = recur(node->right);
            if(deletes.find(node->val) != deletes.end()){
                if(l) res.push_back(l);
                if(r) res.push_back(r);
                return nullptr;
            }
            else{
                node->left = l;
                node->right = r;
            }
            return node;
        };
        if(recur(root)) res.push_back(root);
        return res;
    }
};