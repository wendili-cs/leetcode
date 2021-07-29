// https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> stk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') stk.push(i + 1);
            else if(stk.empty() || stk.top() < 0) stk.push(-(i + 1));
            else stk.pop();
        }
        return stk.size();
    }
};