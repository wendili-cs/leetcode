// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
 // 核心思想：两者的从二叉树到list的方式不同：
//  preorder是：[root, {左子树}, {右子树}]
// inorder是：[{左子树}, root, {右子树}]
// 我们的目的就是每个递归函数要通过左右index来“框”住当前构造的树的子树的范围。所以：
// A. 对于当前树的左子树
    // A1. 对于preorder树，其左子树的左范围指针是它的root index的后面一个，右范围指针是左指针+左子树长度；
    // A2. 对于inorder数，其左子树的左范围指针和自己的左指针一样，右范围指针是root的前面一个
// B. 对于当前树的右子树
    // B1. 对于preorder树，其右子树的左范围指针是左子树的右指针+1，右指针和自己的右指针一样
    // B2. 对于inorder数，其右子树的左范围指针是root+1，右指针和自己的右指针一样
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_index;
        int len = preorder.size();
        for(int i = 0; i < len; i++){
            inorder_index.emplace(inorder[i], i); // 记录value to index
        }
        // 前序遍历的方式造二叉树，中序遍历的方式确定前序造二叉树的最右子节点
        function<TreeNode*(int, int, int, int)> recurr;
        recurr = [&](int preorder_l_idx, int preorder_r_idx, int inorder_l_idx, int inorder_r_idx) -> TreeNode* {
            if(preorder_l_idx > preorder_r_idx){
                return nullptr;
            }
            // 得到当前一层的preorder左边index
            int preorder_root_idx = preorder_l_idx;
            TreeNode* root = new TreeNode(preorder[preorder_root_idx]);
            int inorder_root_idx = inorder_index[preorder[preorder_root_idx]];
            int sizeof_left_subtree = inorder_root_idx - inorder_l_idx;
            root->left = recurr(preorder_root_idx + 1, preorder_root_idx + sizeof_left_subtree, inorder_l_idx, inorder_root_idx - 1);
            root->right = recurr(preorder_root_idx + sizeof_left_subtree + 1, preorder_r_idx, inorder_root_idx + 1, inorder_r_idx);
            return root;
        };
        return recurr(0, len - 1, 0, len - 1);
    }
};