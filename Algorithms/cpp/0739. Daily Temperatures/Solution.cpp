// https://leetcode-cn.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> res(len, 0);
        stack<int> stack;

        for(int i = 0; i < len; i++){
            if(!stack.empty()){
                while(!stack.empty() && T[stack.top()] < T[i]){
                    res[stack.top()] = i - stack.top();
                    stack.pop();
                }
            }
            stack.push(i);
        }
        return res;
    }
};