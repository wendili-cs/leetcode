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
        stack<char>ll1, ll2;
        while(l1){
            ll1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            ll2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *cur = nullptr;
        bool sign = false;
        while(!ll1.empty()||!ll2.empty()||sign){
            int num1, num2, sum;
            if(!ll1.empty()){
                num1 = ll1.top();
                ll1.pop();
            }
            else num1 = 0;
            if(!ll2.empty()){
                num2 = ll2.top();
                ll2.pop();
            }
            else num2 = 0;
            sum = num1 + num2 + sign;
            sign = sum > 9;
            
            ListNode* temp = new ListNode(sum % 10);
            temp->next = cur;
            cur = temp;
        }
        return cur;
    }
};