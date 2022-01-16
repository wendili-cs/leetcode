// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        map<int, vector<int>> mp;
        function<void(int, TreeNode*)> recur;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                auto p = q.front();
                q.pop();
                mp[p.first].push_back(p.second->val);
                if(p.second->left) q.push(make_pair(p.first - 1, p.second->left));
                if(p.second->right) q.push(make_pair(p.first + 1, p.second->right));
            }
        }
        vector<vector<int>> res;
        for(auto& each:mp) res.push_back(each.second);
        return res;
    }
};