// https://leetcode-cn.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        int MAX_LEN  = 10000;
        if(!head || !head->next) return false;
        ListNode *tu = head, *ra = head->next;
        while(tu != ra){
            if(ra == nullptr || ra->next == nullptr) return false;
            tu = tu->next;
            ra = ra->next->next;
        }
        return true;
    }
};