// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        deque<int> stk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                stk.push_back(i + 1); // we store index + 1 for '('
            }
            else if(s[i] == ')'){
                if(!stk.empty() && stk.back() > 0){
                    stk.pop_back();
                }
                else{
                    stk.push_back(-(i + 1)); // we store -(index + 1) for ')'
                }
            }
        }
        string res;
        for(int i = 0; i < s.length(); i++){
            if(!stk.empty() && abs(stk.front()) - 1 == i){
                stk.pop_front();
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};