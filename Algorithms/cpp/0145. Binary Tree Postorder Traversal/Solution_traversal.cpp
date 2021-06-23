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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root, *last = nullptr;
        while(!stk.empty()||cur){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                cur = stk.top();
                if(!cur->right||last==cur->right){ // 没有右下子节点了，或者右下子节点刚刚访问过
                    res.push_back(cur->val);
                    stk.pop();
                    last = cur; // 记录当前指针为上个访问过的
                    cur = nullptr; // 清空当前指针
                }
                else cur = cur->right;
            }
        }
        return res;
    }
};