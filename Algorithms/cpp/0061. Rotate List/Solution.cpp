// https://leetcode-cn.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        if(k == 0 || !head->next) return head;
        int cnt = 1;
        ListNode *cur = head;
        while(cur->next){
            cnt++;
            cur = cur->next;
        }
        cur->next = head;
        k = k % cnt;
        cur = head;
        for(int i = 0; i < cnt - k - 1; i++) cur = cur->next;
        ListNode *res = cur->next;
        cur->next = nullptr;
        head = nullptr;
        return res;
    }
};