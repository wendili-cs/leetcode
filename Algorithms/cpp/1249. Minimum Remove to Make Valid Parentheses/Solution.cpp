// https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        deque<int> stk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                if(stk.empty() || stk.back() < 0) stk.push_back(-(i + 1));
                else stk.pop_back();
            }
            else if(s[i] == '(') stk.push_back(i + 1);
        }
        string res;
        for(int i = 0; i < s.length(); i++){
            if(stk.empty() || i != abs(stk.front()) - 1) res.push_back(s[i]);
            else stk.pop_front();
        }
        return res;
    }
};