// https://leetcode-cn.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        auto merge = [](ListNode* node1, ListNode* node2) -> ListNode* {
            ListNode *fake = new ListNode(), *cur = fake;
            while(node1 != nullptr && node2 != nullptr){
                if(node1->val < node2->val){
                    cur->next = node1;
                    node1 = node1->next;
                }
                else{
                    cur->next = node2;
                    node2 = node2->next;
                }
                cur = cur->next;
            }
            if(node1 != nullptr) cur->next = node1;
            else if(node2 != nullptr) cur->next = node2;
            return fake->next;
        };

        function<ListNode*(ListNode*)> merge_sort;
        merge_sort = [&](ListNode* node) -> ListNode* {
            if(node == nullptr || node->next == nullptr) return node;
            // 快慢指针找中点
            ListNode *s = node, *f = node;
            while(f->next != nullptr && f->next->next != nullptr){
                s = s->next;
                f = f->next->next;
            }
            ListNode *node1 = node, *node2 = s->next;
            s->next = nullptr;
            node1 = merge_sort(node1);
            node2 = merge_sort(node2);
            return merge(node1, node2);
        };

        return merge_sort(head);
    }
};