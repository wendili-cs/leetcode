// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> recur;
        recur = [&](int l, int r) -> TreeNode* {
            if(l > r) return nullptr;
            int mid = (l + r)/2;
            TreeNode *node = new TreeNode(nums[mid]);
            node->left = recur(l, mid - 1);
            node->right = recur(mid + 1, r);
            return node;
        };
        return recur(0, nums.size() - 1);
    }
};