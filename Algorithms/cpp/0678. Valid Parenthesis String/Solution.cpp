// https://leetcode-cn.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> pstk, sstk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                pstk.push(i);
            }
            else if(s[i] == ')'){
                if(!pstk.empty()){
                    pstk.pop();
                }
                else if(!sstk.empty()){
                    sstk.pop();
                }
                else return false;
            }
            else if(s[i] == '*'){
                sstk.push(i);
            }
        }
        while(!pstk.empty()&&!sstk.empty()){
            if(pstk.top() < sstk.top()){
                pstk.pop();
                sstk.pop();
            }
            else return false;
        }
        return pstk.empty();
    }
};