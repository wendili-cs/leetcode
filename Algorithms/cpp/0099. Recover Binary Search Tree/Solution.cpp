// https://leetcode-cn.com/problems/recover-binary-search-tree/

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
    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr; // pre是前一个节点，t1和t2待交换
        vector<TreeNode*> twin;
        function<void(TreeNode*)> inorder;
        inorder = [&](TreeNode* node) -> void {
            if(!node) return;
            inorder(node->left);
            if(pre && pre->val > node->val){
                // 顺序列表[1,2,3,4,5,6]中两个调换了位置[1,5,3,4,2,6]
                // 若pre > cur的情况出现，第一次放入pre和cur（相邻调换），第二次（如果有则不是相邻调换）则替换cur
                if(twin.empty()){
                    twin.push_back(pre);
                    twin.push_back(node);
                }
                else twin[1] = node;
                
            }
            pre = node;
            inorder(node->right);
        };
        inorder(root);
        swap(twin[0]->val, twin[1]->val);
    }
};