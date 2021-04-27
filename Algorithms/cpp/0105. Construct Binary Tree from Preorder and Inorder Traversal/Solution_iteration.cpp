// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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

// 执行用时：12 ms, 在所有 C++ 提交中击败了96.31%的用户
// 内存消耗：24.6 MB, 在所有 C++ 提交中击败了98.24%的用户
// 很巧妙，详情需要复习markdown文件
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return nullptr;
        }
        int len = preorder.size();
        int inorder_idx = 0;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        for(int i = 1; i < len; i++){
            TreeNode* node = stk.top();
            if(node->val == inorder[inorder_idx]){
                // 已经index是最左边了，开始回溯匹配
                while(!stk.empty() && stk.top()->val == inorder[inorder_idx]){
                    node = stk.top();
                    stk.pop();
                    inorder_idx++;
                }
                // 找到的第一个不匹配的，这个时候inorder里面的便是上一个弹出的note的右儿子
                node->right = new TreeNode(preorder[i]);
                stk.push(node->right);
            }
            else{
                // inorder[inorder_idx]是当前节点无限左下走达到的位置，不等于自己说明没没走到头，还有左儿子
                node->left = new TreeNode(preorder[i]);
                stk.push(node->left);
            }
        }
        return root;
    }
};