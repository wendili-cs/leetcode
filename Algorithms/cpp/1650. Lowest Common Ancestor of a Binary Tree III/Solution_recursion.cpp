// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        function<int(Node*, int)> get_depth;
        get_depth = [&](Node* node, int cur)-> int {
            if(node){
                cur++;
                return get_depth(node->parent, cur);
            }
            return cur;
        };
        int p_depth = get_depth(p, 0), q_depth = get_depth(q, 0);
        int diff = abs(p_depth - q_depth);
        for(int i = 0; i < diff; i++){
            if(p_depth > q_depth) p = p->parent;
            else q = q->parent;
        }
        while(p != q){
            p = p->parent;
            q = q->parent;
        }
        return p;
    }
};