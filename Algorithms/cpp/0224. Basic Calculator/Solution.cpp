// https://leetcode-cn.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        vector<int> stack_num(1, 0);
        vector<bool> stack_sign(1, true);
        int temp_num = 0;
        int sign = 1;
        for(const char& c:s){
            if(48 <= (int)c && (int)c <= 57){
                // 读取累积temp_num
                int new_num = c-'0';
                temp_num = temp_num*10 + new_num;
            }
            else if(c == ' ') { continue; }
            else{
                // 结算数字读取
                int e_idx = stack_num.size() - 1;
                stack_num[e_idx] += temp_num*sign;
                temp_num = 0;
            }
            if(c == '+' || c == '-'){
                sign = c == '+'? 1:-1;
            }
            else if(c == '('){
                // 新增一个栈
                string temp = "";
                stack_num.push_back(temp_num);
                stack_sign.push_back(sign==1? true:false);
                temp_num = 0;
                sign = 1;
            }
            else if(c == ')'){
                // 将栈内容回传
                int e_idx = stack_num.size() - 1;
                stack_num[e_idx - 1] += stack_num[e_idx] * (stack_sign[e_idx]? 1:-1);
                stack_num.pop_back();
                stack_sign.pop_back();
            }
        }
        stack_num[0] += temp_num*sign;
        return stack_num[0];
    }
};