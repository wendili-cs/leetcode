// https://leetcode-cn.com/problems/design-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class MyLinkedList {
private:
    int size;
    ListNode *head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = new ListNode(-5);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size) return -1;
        ListNode* node = head;
        for(int cnt = -1; cnt < index; cnt++){
            node = node->next;
        }
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* cur = new ListNode(val), *next;
        next = head->next;
        head->next = cur;
        cur->next = next;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *tail = new ListNode(val), *prev = head;
        while(prev->next) prev = prev->next;
        prev->next = tail;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        else if(index == 0){
            addAtHead(val);
            return;
        }
        ListNode *prev = head, *next;
        for(int cnt = 0; cnt < index; cnt++){
            prev = prev->next;
        }
        ListNode* cur = new ListNode(val);
        next = prev->next;
        prev->next = cur;
        cur->next = next;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        ListNode *prev = head, *next;
        for(int cnt = 0; cnt < index; cnt++){
            prev = prev->next;
        }
        prev->next = prev->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */