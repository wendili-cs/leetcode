// https://leetcode-cn.com/problems/min-stack/

class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        min_stk.push(min_stk.empty()?val:min(min_stk.top(), val));
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */