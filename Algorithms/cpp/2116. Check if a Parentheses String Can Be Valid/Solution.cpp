// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        deque<int> dq, dq2;
        for(int i = 0; i < s.length(); i++){
            if(locked[i] == '0') dq.push_back(i);
            else{
                if(s[i] == '(') dq2.push_back(i);
                else if(s[i] == ')'){
                    if(dq.empty() && dq2.empty())
                        return false;
                    if(!dq2.empty())
                        dq2.pop_back();
                    else dq.pop_front();
                }
            }
        }
        if((dq2.size() + dq.size())%2) return false;
        while(!dq2.empty()){
            if(dq.empty() || dq2.back() > dq.back())
                return false;
            dq.pop_back();
            dq2.pop_back();
        }
        return true;
    }
};