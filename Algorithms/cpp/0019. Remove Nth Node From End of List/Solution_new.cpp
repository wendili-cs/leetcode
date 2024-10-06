// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(), *pre = dummy, *probe = dummy;
        dummy->next = head;
        for(int i = 0; i < n + 1; i++){
            probe = probe->next;
        }
        while(probe){
            probe = probe->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return dummy->next;
    }
};