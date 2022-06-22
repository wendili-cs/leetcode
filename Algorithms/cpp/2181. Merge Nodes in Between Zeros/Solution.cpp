// https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *cur = head, *next = cur->next;
        while(true){
            cur->val += next->val;
            next = next->next;
            if(next-> val == 0){
                if(!next->next) {
                    cur->next = nullptr;
                    break;
                }
                cur->next = next;
                cur = cur->next;
                next = cur->next;
            }
        }
        return head;
    }
};