// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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
    int maxProduct(TreeNode* root) {
        int M = 1000000007;
        unordered_set<int> s;
        function<int(TreeNode*)> recur;
        recur = [&](TreeNode* node) -> int {
            if(!node) return 0;
            int left = recur(node->left);
            int right = recur(node->right);
            int sum = (left + right + node->val);
            s.insert(sum);
            return sum;
        };
        long tsum = recur(root), res = 0;
        for(auto it:s){
            long prod = (tsum - it)*it;
            res = res >  prod? res:prod;
        }
        return res%M;
    }
};