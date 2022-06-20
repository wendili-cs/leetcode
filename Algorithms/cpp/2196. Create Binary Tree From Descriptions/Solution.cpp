// https://leetcode.com/problems/create-binary-tree-from-descriptions/submissions/

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mp;
        map<int, int> parents;
        TreeNode *root;
        for(auto des:descriptions){
            if(mp[des[0]] == nullptr){
                mp[des[0]] = new TreeNode(des[0]);
            }
            if(mp[des[1]] == nullptr){
                mp[des[1]] = new TreeNode(des[1]);
            }
            if(des[2]) mp[des[0]]->left = mp[des[1]];
            else mp[des[0]]->right = mp[des[1]];
            parents[des[1]] = des[0];
        }
        int t = mp.begin()->second->val;
        while(parents.find(t) != parents.end()){
            t = parents[t];
        }
        return mp[t];
    }
};