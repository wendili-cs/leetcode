// https://leetcode-cn.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *fast = newHead, *slow = newHead;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *latter = slow->next;
        slow->next = nullptr;
        // 反转前半部分
        ListNode *fake = new ListNode(-1);
        fake->next = head;
        ListNode *pre = fake, *cur = pre->next, *next;
        while(cur->next){
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        // 开始比较
        fake = fake->next;
        if(fast->next) latter = latter->next; // 奇数个元素，中间那个跳过
        while(fake && latter){
            if(fake->val != latter->val) return false;
            fake = fake->next;
            latter = latter->next;
        }
        return true;
    }
};