// https://leetcode-cn.com/problems/add-two-numbers/

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
        ListNode *sum = new ListNode(-1), *p1 = l1, *p2 = l2;
        ListNode *ptemp = sum;
        bool flag = false;
        while(p1 != nullptr || p2 != nullptr || flag){
            ListNode *pnew = new ListNode();
            if(flag){
                pnew->val += 1;
                flag = false;
            }
            if(p1 != nullptr){
                pnew->val += p1->val;
                p1 = p1->next;
            }
            if(p2 != nullptr){
                pnew->val += p2->val;
                p2 = p2->next;
            }
            if(pnew->val >= 10){
                flag = true;
                pnew->val = (pnew->val) % 10;
            }
            ptemp->next = pnew;
            ptemp = ptemp->next;
        }
        return sum->next;
    }
};