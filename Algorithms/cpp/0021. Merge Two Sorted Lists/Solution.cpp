// https://leetcode-cn.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* ptr3 = new ListNode();
        ListNode* l_res = ptr3;
        while(ptr1 != nullptr || ptr2 != nullptr){
            ptr3->next = new ListNode();
            ptr3 = ptr3->next;
            if(ptr1 == nullptr){
                ptr3->val = ptr2->val;
                ptr2 = ptr2->next;
            }
            else if(ptr2 == nullptr || ptr1->val <= ptr2->val){
                ptr3->val = ptr1->val;
                ptr1 = ptr1->next;
            }
            else{ // 和第一种是同情况，但是不能把判断语句放一起，因为可能ptr2是nullptr
                ptr3->val = ptr2->val;
                ptr2 = ptr2->next;
            }
        }
        return l_res->next;
    }
};