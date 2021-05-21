// https://leetcode-cn.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        bool has_cycle = false;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                has_cycle = true;
                break;
            }
        }

        if(has_cycle){
            ListNode *res = head;
            while(res != slow){
                res = res->next;
                slow = slow->next;
            }
            return res;
        }
        return nullptr;
    }
};