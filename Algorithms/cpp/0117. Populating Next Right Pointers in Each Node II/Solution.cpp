// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(root->left && root->right) root->left->next = root->right;
        if(root->right) root->right->next = get_next(root->next);
        else if(root->left) root->left->next = get_next(root->next);
        connect(root->right);
        connect(root->left);
        return root;
    }

    Node* get_next(Node* node){ // 下一级的next
        if(!node) return node;
        if(node->left) return node->left;
        if(node->right) return node->right;
        if(node->next) return get_next(node->next);
        return nullptr;
    }
};