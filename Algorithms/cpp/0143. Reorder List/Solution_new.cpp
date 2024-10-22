// https://leetcode.com/problems/reorder-list/

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
        if(!head->next) return; // 只有一个node情况
        ListNode *dummy = new ListNode(), *fast = head, *pre_slow = dummy;
        dummy->next = head;
        while(fast && fast->next){ 
            // 快慢指针找中点，这里pre_slow故意后一步出发从而可以得到slow前一个
            // 所以奇数情况下比如[1,2,3,4,5], pre_slow在2；偶数情况比如[1,2,3,4], pre_slow也在2
            pre_slow = pre_slow->next;
            fast = fast->next->next;
        }
        // 反转后半部分链表，从cur开始反转
        ListNode *pre = pre_slow, *cur = pre_slow->next, *next;
        while(cur && cur->next){
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        ListNode *slow = pre_slow->next;
        pre_slow->next = nullptr;
        while(head){ // 此时head数量和slow数量相同，或者slow比head多一个
            ListNode *headnext = head->next, *slownext = slow->next; // 临时存head和slow的原本下一个node
            head->next = slow;
            // slow可能比head多一个，如果head先用完了(headnext=nullptr)，slow不要断开和自己的下一个的链接
            if(headnext) slow->next = headnext; 
            head = headnext;
            slow = slownext;
        }
    }
};