// https://leetcode-cn.com/problems/sum-lists-lcci/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool flag = false;
        int num;
        ListNode *fake = new ListNode(), *cur = fake;
        while(l1 || l2){
            num = flag + (l1? l1->val:0) + (l2? l2->val:0);
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            flag = num >= 10;
            num = num % 10;
            cur->next = new ListNode(num);
            cur = cur->next;
        }
        if(flag){
            cur->next = new ListNode(flag);
        }
        return fake->next;
    }
};