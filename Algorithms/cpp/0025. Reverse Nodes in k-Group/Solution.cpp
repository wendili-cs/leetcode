// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead = new ListNode();
        newHead->next = head;

        auto reverseLtoR = [&](int l, int r) -> void {
            ListNode* prev = newHead;
            for(int i = 0; i < l - 1; i++){
                prev = prev->next;
            }
            ListNode* cur = prev->next;
            ListNode* next;
            for(int i = 0; i < r - l; i++){
                next = cur->next;
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
        };

        int len = 0;
        ListNode* cur = newHead;
        while(cur->next != nullptr){
            cur = cur->next;
            len += 1;
        }

        for(int i = 0; (i + 1)*k <= len; i++){
            reverseLtoR(i*k + 1, (i + 1)*k);
        }
        return newHead->next;
    }
};