// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* recur(Node* node) {
        // return the last node of one level reursively
        while(node){
            if(node->child){
                Node *child = node->child, *child_end = recur(node->child), *next = node->next;
                node->child = nullptr;
                node->next = child;
                child->prev = node;
                if(next) next->prev = child_end;
                child_end->next = next;
            }
            if(node->next) node = node->next;
            else break;
        }
        return node;
    }
    
    Node* flatten(Node* head) {
        recur(head);
        return head;
    }
};