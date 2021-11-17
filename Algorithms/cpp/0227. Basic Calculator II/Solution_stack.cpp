// https://leetcode.com/problems/basic-calculator-ii/


class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> stk;
        int b = 0, last_sign = 0;
        map<char, int> m = {{'+', 0}, {'-', 1}, {'*', 2}, {'/', 3}};
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c == ' ') continue;
            else if(c < '0'){
                if(last_sign == 0) stk.push(b);
                else if(last_sign == 1) stk.push(-b);
                else if(last_sign == 2 || last_sign == 3){
                    int a = stk.top();
                    stk.pop();
                    stk.push(last_sign==2?a*b:a/b);
                }
                b = 0;
                last_sign = m[c];
            }
            else{
                b = b*10 + (c - '0');
            }
        }
        int res = 0;
        for(; !stk.empty(); stk.pop()) res += stk.top();
        return res;
    }
};