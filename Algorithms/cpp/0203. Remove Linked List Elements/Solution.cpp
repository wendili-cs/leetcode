// https://leetcode-cn.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *fake = new ListNode(), *prev = fake;
        fake->next = head;
        while(prev && prev->next){
            if(prev->next->val == val) prev->next = prev->next->next;
            else prev = prev->next;
        }
        return fake->next;
    }
};