// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        unordered_map<int, int> umap; // 数值 -> index
        for(int i = 0; i < len; i++) umap[inorder[i]] = i;

        function<TreeNode*(int, int, int, int)> recur;
        recur = [&](int il, int ir, int pl, int pr) -> TreeNode* {
            int root_val = postorder[pr]; // 当前根节点的值
            int root_idxi = umap[root_val]; // 中序遍历中根节点的index
            int left_len = root_idxi - il;
            int right_len = ir - root_idxi;
            TreeNode* node = new TreeNode(root_val);
            if(left_len > 0) node->left = recur(il, il + left_len - 1, pl, pl + left_len - 1);
            if(right_len > 0) node->right = recur(root_idxi + 1, root_idxi + right_len, pr - right_len, pr - 1);
            return node;
        };
        return recur(0, len - 1, 0, len - 1);
    }
};