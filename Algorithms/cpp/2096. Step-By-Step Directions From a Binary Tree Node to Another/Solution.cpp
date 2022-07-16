// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
    map<int, string> mp;
    
    string dfs(TreeNode* node, int val) {
        if(!node) return "";
        else if(node->val == val) return "X";
        string left = dfs(node->left, val), right = dfs(node->right, val);
        if(!left.empty()){
            left.push_back('L');
            return left;
        }
        else if(!right.empty()){
            right.push_back('R');
            return right;
        }
        return "";
    };
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string to_s = dfs(root, startValue), to_d = dfs(root, destValue);
        reverse(to_s.begin(), to_s.end());
        reverse(to_d.begin(), to_d.end());
        to_s.pop_back();
        to_d.pop_back();
        int idx = 0;
        while(idx < to_s.length() && idx < to_d.length() && to_s[idx] == to_d[idx]) idx++;
        string res(to_s.length() - idx, 'U');
        res += to_d.substr(idx);
        return res;
    }
};