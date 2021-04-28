// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);
        bool left2right = true;
        while(!q.empty()){
            int level_size = q.size();
            vector<int> temp;
            for(int i = 0; i < level_size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(left2right) temp.push_back(node->val);
                else temp.insert(temp.begin(), node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            left2right = !left2right;
            res.push_back(temp);
        }
        return res;
    }
};