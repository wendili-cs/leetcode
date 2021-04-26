// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode* pre = newHead;
        ListNode *cur, *next;
        while(pre->next != nullptr){
            cur = pre->next;
            next = cur->next;
            if(next != nullptr && cur->val == next->val){
                while(next != nullptr && cur->val == next->val){
                    next = next->next;
                }
                pre->next = next;
            }
            else{
                pre = pre->next;
            }
        }
        return newHead->next;
    }
};