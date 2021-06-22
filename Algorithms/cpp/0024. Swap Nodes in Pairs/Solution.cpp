// https://leetcode-cn.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *fake = new ListNode(), *pre = fake, *cur, *next;
        fake->next = head;
        while(pre && pre->next){
            cur = pre->next;
            next = cur->next;
            if(!next) break;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            pre = next->next;
        }
        return fake->next;
    }
};