// https://leetcode-cn.com/problems/reverse-linked-list-ii/

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
    void reverseLinkList(ListNode* lk){
        ListNode* prev = nullptr;
        ListNode* cur = lk;
        while(cur != nullptr){
            ListNode* follow = cur->next;
            cur->next = prev;
            prev = cur;
            cur = follow;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *l_ptr, *ll_ptr, *r_ptr, *rr_ptr;
        ListNode *newHead = new ListNode();
        newHead->next = head;
        ListNode* cur = newHead;
        for(int i = 0; i <= right; i++){ // 顺序ll, l, r, rr
            if(i == left - 1){
                ll_ptr = cur;
                l_ptr = cur->next;
            }
            else if(i == right){
                r_ptr = cur;
                rr_ptr = cur->next;
                break;
            }
            cur = cur->next;
        }
        ll_ptr->next = nullptr;
        r_ptr->next = nullptr;
        reverseLinkList(l_ptr);
        ll_ptr->next = r_ptr;
        l_ptr->next = rr_ptr;
        
        return newHead->next;
    }
};