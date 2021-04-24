// https://leetcode-cn.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        int len = -1;
        ListNode *cur = head;
        while(cur != nullptr){
            len += 1;
            cur = cur->next;
        }
        if(len == 0){
            return;
        }
        int start_idx = len/2;
        ListNode *pre = head;
        for(int i = 0; i < start_idx; i++){
            pre = pre->next;
        }

        ListNode *mark_pre = pre;
        cur = pre->next;
        ListNode *next;
        while(cur->next != nullptr){
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        ListNode *ptr1 = head, *ptr2 = mark_pre->next;
        while(ptr2 != nullptr && ptr1 != nullptr){ //ptr1 != mark_pre->next && 
            mark_pre->next = ptr2->next;
            ListNode* temp = ptr1->next;
            ptr1->next = ptr2;
            ptr2->next = temp;
            ptr2 = mark_pre->next;
            ptr1 = temp;
        }
    }
};