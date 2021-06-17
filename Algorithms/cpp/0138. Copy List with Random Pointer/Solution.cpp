// https://leetcode-cn.com/problems/copy-list-with-random-pointer/

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
        unordered_map<Node*, Node*> v2n;
        Node *root = new Node(-1), *cur = root;
        while(head){
            if(v2n.find(head) != v2n.end()){
                cur->next = v2n[head];
            }
            else{
                cur->next = new Node(head->val);
                v2n[head] = cur->next;
            }
            cur = cur->next;
            if(head->random){
                if(v2n.find(head->random) != v2n.end()){
                    cur->random = v2n[head->random];
                }
                else{
                    cur->random = new Node(head->random->val);
                    v2n[head->random] = cur->random;
                }
            }
            head = head->next;
        }
        return root->next;
    }
};