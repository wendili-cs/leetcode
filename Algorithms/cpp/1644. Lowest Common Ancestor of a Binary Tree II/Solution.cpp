// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> par;
        queue<TreeNode*> qt;
        qt.push(root);
        int depth = 1, p_dep, q_dep;
        while(!qt.empty()){
            int q_size = qt.size();
            for(int i = 0; i < q_size; i++){
                TreeNode* node = qt.front();
                qt.pop();
                if(node->val == p->val) p_dep = depth;
                else if(node->val == q->val) q_dep = depth;
                if(node->left){
                    par[node->left] = node;
                    qt.push(node->left);
                }
                if(node->right){
                    par[node->right] = node;
                    qt.push(node->right);
                }
            }
            depth++;
        }
        par[root] = new TreeNode();
        if(!par[p] || !par[q]) return nullptr;
        int diff = abs(p_dep - q_dep);
        for(int i = 0; i < diff; i++){
            if(p_dep > q_dep) p = par[p];
            else q = par[q];
        }
        while(p != q){
            p = par[p];
            q = par[q];
        }
        return p;
    }
};