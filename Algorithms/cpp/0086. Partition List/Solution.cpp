// https://leetcode-cn.com/problems/partition-list

// 维护两个链表，一个所有值小于x，一个所有值大于等于x，
// 遍历原始链表，当值小于x时。cur_less指向该节点，
// 当值大于等于x时，cur_greater指向该节点。
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *head_less = new ListNode(), *head_greater = new ListNode();
        ListNode *cur_less = head_less, *cur_greater = head_greater;
        while(head){
            if(head->val < x){
                cur_less->next = head;
                cur_less = cur_less->next;
            }
            else{
                cur_greater->next = head;
                cur_greater = cur_greater->next;
            }
            head = head->next;
        }
        cur_greater->next = nullptr;
        cur_less->next = head_greater->next;
        return head_less->next;
    }
};