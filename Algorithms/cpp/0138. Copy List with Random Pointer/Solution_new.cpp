// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(-1), *pre = dummy;
        unordered_map<Node*, Node*> mp;
        while(head){
            if(mp.find(head) == mp.end()){
                // 未找到这个node，则创建它并加入键值对
                mp[head] = new Node(head->val);
            }
            pre->next = mp[head];
            if(head->random && mp.find(head->random) == mp.end()){
                // 未找到这个random node，则创建它并加入键值对
                mp[head->random] = new Node(head->random->val);
            }
            mp[head]->random = mp[head->random];
            pre = pre->next;
            head = head->next;
        }
        return dummy->next;
    }
};