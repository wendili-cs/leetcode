// https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(char c:s){
            if(c == ')' && !stk.empty() && stk.top() == '('){ // 只有上一个是"(",下一个是")"，才会抵消
                stk.pop();
            }
            else{
                stk.push(c); // 不然就把c加入stack
            }
        }
        return stk.size();
    }
};