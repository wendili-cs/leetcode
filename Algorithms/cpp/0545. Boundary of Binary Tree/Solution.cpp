// https://leetcode-cn.com/problems/boundary-of-binary-tree/

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
private:
    vector<int> res;
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return res;
        res.push_back(root->val);
        if(root->left) get_left_boundary(root->left);
        if(root->left || root->right) get_leaves(root);
        if(root->right) get_right_boundary(root->right);
        return res;
    }

    void get_left_boundary(TreeNode* node){
        if(!node->left && !node->right) return; // 叶子节点
        res.push_back(node->val);
        if(node->left) get_left_boundary(node->left);
        else if(node->right) get_left_boundary(node->right);
    }

    void get_right_boundary(TreeNode* node){
        if(!node->left && !node->right) return; // 叶子节点
        if(node->right) get_right_boundary(node->right);
        else if(node->left) get_right_boundary(node->left);
        res.push_back(node->val);
    }

    void get_leaves(TreeNode* node){
        if(!node->left && !node->right){
            res.push_back(node->val);
            return;
        }
        if(node->left) get_leaves(node->left);
        if(node->right) get_leaves(node->right);
    }
};