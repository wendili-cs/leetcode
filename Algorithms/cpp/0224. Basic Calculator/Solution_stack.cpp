// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        stack<int> stk; // signs stack, each element is +1 or -1
        stk.push(1);
        int cur_num = 0, res = 0, sign = 1;
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                int cur_num = s[i] - '0';
                while(i + 1 < s.length() && isdigit(s[i + 1])){
                    cur_num = cur_num*10 + (s[i + 1] - '0');
                    i++;
                }
                res += cur_num*sign;
            }
            else if(s[i] == ' ') continue;
            else if(s[i] == '+'){
                sign = stk.top();
            }
            else if(s[i] == '-'){
                sign = -stk.top();
            }
            else if(s[i] == '('){
                stk.push(sign);
            }
            else if(s[i] == ')'){
                stk.pop();
            }
        }
        return res;
    }
};