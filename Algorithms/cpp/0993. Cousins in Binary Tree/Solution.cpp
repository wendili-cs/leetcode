// https://leetcode.com/problems/cousins-in-binary-tree/

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qsize = q.size();
            unordered_set<int> s;
            for(int i = 0; i < qsize; i++){
                TreeNode* node = q.front();
                q.pop();
                s.insert(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(node->left && node->right){
                    if((node->left->val == x && node->right->val == y) ||
                    (node->left->val == y && node->right->val == x))
                        return false; // the case they have the same parent
                }
            }
            if(s.find(x) != s.end()){
                return s.find(y) != s.end();
            }
        }
        return true; // impossible step
    }
};