// https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key > root->val) root->right = deleteNode(root->right, key);
        else if(key < root->val) root->left = deleteNode(root->left, key);
        else{
            if(!root->left && !root->right) return nullptr; // no child
            else if(!root->left) return root->right;
            else if(!root->right) return root->left;
            else{ // both children exist
                TreeNode* node = root->left;
                while(node->right) node = node->right; // find the next node that comes in the inorder traversal
                root->val = node->val; // copy the value of the next node
                root->left = deleteNode(root->left, node->val); // remove the next node because we already copied it
            }
        }
        return root;
    }
};