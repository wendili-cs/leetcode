// https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stack_vec(1, "");
        for(const char c:s){
            if(c == '('){
                string temp = "";
                stack_vec.push_back(temp);
            }
            else if(c == ')'){
                int end_idx = stack_vec.size() - 1;
                reverse(stack_vec[end_idx].begin(), stack_vec[end_idx].end());
                stack_vec[end_idx - 1] += stack_vec[end_idx];
                stack_vec.pop_back();
            }
            else{
                int end_idx = stack_vec.size() - 1;
                stack_vec[end_idx] += c;
            }
        }
        return stack_vec[0];
    }
};