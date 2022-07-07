// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    int pairSum(ListNode* head) {
        int res = 0;
        ListNode *fake = new ListNode(), *slow = fake, *fast = fake;
        fake->next = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *pre = slow, *cur = pre->next, *next;
        while(cur && cur->next){
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        slow = slow->next;
        while(slow){
            res = max(res, slow->val + head->val);
            slow = slow->next;
            head = head->next;
        }
        return res;
    }
};