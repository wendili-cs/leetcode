// https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    Node (int _val) {
        val = _val;
    };
    
    int evaluate(){
        return val;
    };
protected:
    int val;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<int> stk;
        for(string& str:postfix){
            if(!(str=="+"||str=="-"||str=="*"||str=="/")){
                stk.push(stoi(str));
            }
            else{
                int par1 = stk.top();
                stk.pop();
                int par2 = stk.top();
                stk.pop();
                if(str=="+") stk.push(par2 + par1);
                else if(str=="-") stk.push(par2 - par1);
                else if(str=="*") stk.push(par2 * par1);
                else stk.push(par2 / par1);
            }
        }
        Node* node = new Node(stk.top());
        return node;
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */