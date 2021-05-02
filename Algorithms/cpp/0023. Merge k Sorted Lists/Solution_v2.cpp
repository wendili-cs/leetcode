// https://leetcode-cn.com/problems/merge-k-sorted-lists/

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
// 思路：维护一个优先队列，每次把最小的pop出来放入结果，如果这个最小的next不为空指针，则优先队列再插入其next元素
struct cmp
{
    bool operator() (ListNode* A, ListNode* B) 
    {
        return A->val > B->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int len = lists.size();

        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i = 0; i < len; i++){
            if(lists[i] != nullptr){
                q.emplace(lists[i]);
            }
        }

        while(!q.empty()){
            int idx;
            ListNode* node = q.top();;
            q.pop();
            if(node->next){
                q.emplace(node->next);
            }
            cur->next = node;
            cur = cur->next;
        }
        return head->next;
    }
};