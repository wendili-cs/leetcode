// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    bool isdigit_str(string &s){
        int i = 0;
        if(s.length() > 1 && (s[i] == '+' || s[i] == '-')) i++;
        else if(s[i] == '+' || s[i] == '-') return false;
        for(;i < s.length(); i++){
            if(!isdigit(s[i])) return false;
        }
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto& s:tokens){
            if(isdigit_str(s)){
                nums.push(stoi(s));
            }
            else{
                int sec = nums.top();
                nums.pop();
                int fir = nums.top();
                nums.pop();
                int res;
                if(s == "+") res = fir + sec;
                else if(s == "-") res = fir - sec;
                else if(s == "*") res = fir * sec;
                else if(s == "/") res = fir / sec;
                nums.push(res);
            }
        }
        return nums.top();
    }
};