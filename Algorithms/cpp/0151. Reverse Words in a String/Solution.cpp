// https://leetcode-cn.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        stack<string> stk;
        int len = s.length(), l = 0;
        for(int r = 0; r < len; r++){
            if(s[r] == ' '||r == len - 1){
                if(r >= l) stk.push(s.substr(l, r-l+1));
                l = r + 1;
            }
        }
        string res;
        while(!stk.empty()){
            if(stk.top() != " ") res += stk.top();
            stk.pop();
        }
        res.pop_back();
        return res;
    }
};