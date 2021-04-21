// https://leetcode-cn.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        bool res = true;
        stack<char> brackets;
        unordered_map<char, char> bracket_pair;
        bracket_pair.emplace(')', '(');
        bracket_pair.emplace(']', '[');
        bracket_pair.emplace('}', '{');
        for(const auto& bracket : s){
            auto iter = bracket_pair.find(bracket);
            if(iter == bracket_pair.end()){
                brackets.push(bracket);
            }
            else{
                if(!brackets.empty() && brackets.top() == iter->second){
                    brackets.pop();
                }
                else{
                    res = false;
                }
            }
        }
        return brackets.empty()? res : false;
    }
};