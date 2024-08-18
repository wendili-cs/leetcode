// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        stack<int> stk; // sign stack
        stk.push(1);
        int cur, res = 0, sign = 1, i = 0;
        while(i < s.length()){
            if(isdigit(s[i])){
                cur = 0;
                while(i < s.length() && isdigit(s[i])){
                    cur = 10*cur + (s[i] - '0');
                    i++;
                }
                res += sign*cur;
                continue;
            }
            else if(s[i] == '(') stk.push(sign);
            else if(s[i] == ')') stk.pop();
            else if(s[i] == '+') sign = stk.top();
            else if(s[i] == '-') sign = -stk.top();
            i++;
        }
        return res;
    }
};