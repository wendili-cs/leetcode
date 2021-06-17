// https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/comments/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
// 要点：一个hash表一个小顶堆，先遍历一遍树再构造
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        priority_queue<int, vector<int>, greater<int> > pq;
        unordered_map<int, Node*> umap;
        function<void(Node*)> recur;
        recur = [&](Node* node) -> void {
            pq.push(node->val);
            umap[node->val] = node;
            if(node->left) recur(node->left);
            if(node->right) recur(node->right);
        };
        recur(root);
        Node *head = umap[pq.top()], *cur = head;
        pq.pop();
        while(!pq.empty()){
            cur->right = umap[pq.top()];
            pq.pop();
            Node* next = cur->right;
            next->left = cur;
            cur = next;
        }
        cur->right = head;
        head->left = cur;
        return head;
    }
};