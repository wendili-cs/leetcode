// https://leetcode-cn.com/problems/maximum-width-of-binary-tree/

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
//  要点：存储每个树节点的排序值
//  要点2：使用一个base，每次减去避免爆炸
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 1;
        queue<pair<int, TreeNode*> > q;
        q.push(make_pair(0, root));
        while(!q.empty()){
            int q_size = q.size();
            int wmin = INT_MAX, wmax = INT_MIN, base = q.front().first*2;
            for(int i = 0; i < q_size; i++){
                TreeNode* node = q.front().second;
                int idx = q.front().first;
                wmin = min(wmin, idx);
                wmax = max(wmax, idx);
                q.pop();
                if(node->left){
                    q.push(make_pair(2*idx - base, node->left));
                }
                if(node->right){
                    q.push(make_pair(2*idx + 1 - base, node->right));
                }
            }
            res = max(res, wmax - wmin + 1);
        }
        return res;
    }
};