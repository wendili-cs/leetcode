// https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/

class MaxQueue {
private:
    deque<int> q, m;
public:
    MaxQueue() {

    }
    
    int max_value() {
        return m.empty()?-1:m.front();
    }
    
    void push_back(int value) {
        q.push_back(value);
        while(!m.empty() && m.back() < value) m.pop_back();
        m.push_back(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int ret = q.front();
        if(m.front() == ret) m.pop_front();
        q.pop_front();
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */