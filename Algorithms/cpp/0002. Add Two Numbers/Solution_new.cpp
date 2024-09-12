// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(), *cur = dummy;
        int carryover = 0;
        while(l1 || l2){
            if(l1){
                carryover += l1->val;
                l1 = l1->next;
            }
            if(l2){
                carryover += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(carryover%10);
            cur = cur->next;
            carryover = carryover/10;
        }
        if(carryover > 0){
            cur->next = new ListNode(carryover);
        }
        return dummy->next;
    }
};