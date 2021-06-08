// https://leetcode-cn.com/problems/calculator-lcci/

class Solution {
public:
    int calculate(string s) {
        const int ADD = 1, MINUS = 2, MULT = 3, DIVI = 4;
        stack<int> nums;
        stack<int> symbols;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                int i2 = i;
                while(i2 < s.length() && isdigit(s[i2])) i2++;
                int temp = stoi(s.substr(i, i2 - i));
                if(!symbols.empty() && (symbols.top() == MULT || symbols.top() == DIVI)){
                    int temp2 = nums.top();
                    nums.pop();
                    nums.push(symbols.top() == MULT? temp2*temp:temp2/temp);
                    symbols.pop();
                }
                else nums.push(temp);
                i = i2 - 1;
            }
            else if(s[i] == '+'||s[i] == '-'||s[i] == '*'||s[i] == '/'){
                if(s[i] == '+') symbols.push(ADD);
                else if(s[i] == '-') symbols.push(MINUS);
                else if(s[i] == '*') symbols.push(MULT);
                else if(s[i] == '/') symbols.push(DIVI);
            }
        }
        int res = 0;
        while(!symbols.empty()){
            int temp = nums.top();
            nums.pop();
            if(symbols.top() == ADD) res += temp;
            else res -= temp;
            symbols.pop();
        }
        if(!nums.empty()) res += nums.top();
        return res;
    }
};