// https://leetcode-cn.com/problems/add-two-numbers-ii/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1, stk2;
        while(l1){
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            stk2.push(l2->val);
            l2 = l2->next == nullptr? nullptr:l2->next;
        }
        int addition = 0;
        ListNode* cur = nullptr;
        while(!stk1.empty() || !stk2.empty() || addition == 1){
            int n1 = 0, n2 = 0;
            if(!stk1.empty()){
                n1 = stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()){
                n2 = stk2.top();
                stk2.pop();
            }
            int val = (n1 + n2 + addition)%10;
            addition =  (n1 + n2 + addition)/10;
            ListNode* node = new ListNode(val);
            node->next = cur;
            cur = node;
        }
        return cur;
    }
};