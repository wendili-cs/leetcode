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
// 思路：最直接的方法，每次check所有lists是否还存在元素，全部不存在的时候结束
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int len = lists.size();
        auto check_end = [&]() -> bool {
            for(int i = 0; i < len; i++){
                if(lists[i] != nullptr) return false;
            }
            return true;
        };
        while(!check_end()){
            pair<int, ListNode*> temp_node = {-1, nullptr};
            for(int i = 0; i < len; i++){
                if(lists[i] != nullptr){
                    if(temp_node.second == nullptr || temp_node.second->val > lists[i]->val){
                        temp_node.second = lists[i];
                        temp_node.first = i;
                    }
                }
            }
            if(temp_node.first != -1){
                lists[temp_node.first] = lists[temp_node.first]->next;
                cur->next = temp_node.second;
                cur = cur->next;
            }
        }
        return head->next;
    }
};