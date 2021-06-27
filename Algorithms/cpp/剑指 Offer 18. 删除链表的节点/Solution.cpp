// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/

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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *fake = new ListNode(), *pre = fake, *cur;
        fake->next = head;
        while(pre && pre->next){
            cur = pre->next;
            if(cur->val == val) pre->next = cur->next;
            pre = pre->next;
        }
        return fake->next;
    }
};