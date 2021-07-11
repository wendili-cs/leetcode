// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return {};
        else if(!head->next) return new TreeNode(head->val);
        ListNode *pre = head, *cur = pre->next, *tail = cur->next; 
        while(tail && tail->next){
            cur = pre->next;
            pre = cur;
            tail = tail->next->next;
        }
        cur = pre->next;
        pre->next = nullptr;
        TreeNode *ret = new TreeNode(cur->val, sortedListToBST(head), sortedListToBST(cur->next));
        return ret;
    }
};