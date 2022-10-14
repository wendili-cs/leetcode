// https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack {
private:
    unordered_map<int, int> freqs;
    unordered_map<int, stack<int>> freq2stk;
    int max_freq;
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        int freq = ++freqs[val];
        max_freq = max(max_freq, freq);
        freq2stk[freq].push(val);
    }
    
    int pop() {
        int ret = freq2stk[max_freq].top();
        freq2stk[max_freq].pop();
        if(freq2stk[max_freq].empty()) max_freq--;
        freqs[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */