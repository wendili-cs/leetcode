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
        if(p == q) return p;
        int level_p = 0, level_q = 0; // 统计p和q所在的层级
        Node *n1 = p, *n2 = q;
        while(n1){
            n1 = n1->parent;
            level_p++;
        }
        while(n2){
            n2 = n2->parent;
            level_q++;
        }
        while(p != q){
            // 先把更深层级的提上来
            if(level_p > level_q){
                p = p->parent;
                level_p--;
            }
            else if(level_p < level_q){
                q = q->parent;
                level_q--;
            }
            // 此刻条件为：level_p == level_q，这时一起提它们
            else{
                p = p->parent;
                q = q->parent;
            }
        }
        return p;
    }
};