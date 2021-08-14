// https://leetcode-cn.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
private:
    vector<TreeNode*> inorder;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            inorder.push_back(root);
            root = root->left;
        }
    }
    
    int next() {
        int ret = inorder.back()->val;
        TreeNode* node = inorder.back()->right;
        inorder.pop_back();
        while(node){
            inorder.push_back(node);
            node = node->left;
        }
        return ret;
    }
    
    bool hasNext() {
        return !inorder.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */