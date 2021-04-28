// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr){
            return nullptr;
        }
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        queue<ListNode*> q;
        ListNode* cur = newHead;
        while(cur != nullptr){
            if(q.size() > n){
                q.pop();
            }
            q.push(cur);
            cur = cur->next;
        }
        ListNode* pre = q.front();
        q.pop();
        q.pop();
        ListNode* next = q.empty()? nullptr:q.front();
        pre->next = next;
        return newHead->next;
    }
};