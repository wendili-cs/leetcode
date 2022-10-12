// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        int l = 0;
        stack<string> stk;
        stack<int> stk2;
        string cur;
        while(l < s.length()){
            if(isdigit(s[l])){
                int r = l;
                while(r < s.length() && isdigit(s[r])) r++;
                stk2.push(stoi(s.substr(l, r - l)));
                l = r;
                stk.push(cur); // here the s[l] == '['
                cur = "";
            }
            else if(s[l] == ']'){
                string tmp;
                for(int i = 0; i < stk2.top(); i++) tmp += cur;
                cur = stk.top() + tmp;
                stk.pop();
                stk2.pop();
            }
            else{
                // is letter character
                int r = l;
                while(r < s.length() && isalpha(s[r])) r++;
                cur += s.substr(l, r - l);
                l = r;
                continue;
            }
            l++;
        }
        return cur;
    }
};