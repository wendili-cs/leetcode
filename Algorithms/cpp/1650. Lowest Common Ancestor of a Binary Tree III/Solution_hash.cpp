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
        unordered_map<Node*, int> ump1, ump2;
        Node* res;
        int cnter1 = 0, cnter2 = 0, idx = INT_MAX;
        while(p){
            ump1[p] = cnter1;
            cnter1++;
            p = p->parent;
        }
        while(q){
            ump2[q] = cnter2;
            cnter2++;
            q = q->parent;
        }
        for(auto it = ump1.begin(); it != ump1.end(); it++){
            if(ump2.find(it->first) != ump2.end() && idx > it->second){
                idx = it->second;
                res = it->first;
            }
        }
        return res;
   }
};