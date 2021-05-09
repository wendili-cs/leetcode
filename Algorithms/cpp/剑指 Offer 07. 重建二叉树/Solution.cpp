// https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> umap;
        int len = preorder.size();
        for(int i = 0; i < len; i++){
            umap[inorder[i]] = i; // 查询inorder里面的节点对应
        }
        function<TreeNode*(int, int, int, int)> recurr;
        recurr = [&](int p_l, int p_r, int i_l, int i_r) -> TreeNode* {
            if(p_l > p_r || i_l > i_r) return nullptr;
            TreeNode* cur_node = new TreeNode(preorder[p_l]);
            int i_root_idx = umap[preorder[p_l]];
            int left_size = i_root_idx - i_l, right_size = p_r - p_l - left_size;
            if(left_size > 0){
                TreeNode* left_node = recurr(p_l + 1, p_l + left_size, i_l, i_r - right_size - 1);
                cur_node->left = left_node;
            }
            if(right_size > 0){
                TreeNode* right_node = recurr(p_l + 1 + left_size, p_r, i_l + 1 +left_size, i_r);
                cur_node->right = right_node;
            }
            
            return cur_node;
        };
        return recurr(0, len - 1, 0, len - 1);
    }
};