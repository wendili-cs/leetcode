// https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode *last = head, *cur = head;
        for(int i = 0; i < k; i++){
            last = last->next;
        }
        while(last){
            last = last->next;
            cur = cur->next;
        }
        return cur->val;
    }
};