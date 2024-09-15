// https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        auto is_valid = [](string t) -> bool {
            stack<char> stk;
            for(int i = 0; i < t.length(); i++){
                if(stk.empty() && t[i] == ')') return false;
                else if(t[i] == ')') stk.pop();
                else if(t[i] == '(') stk.push('(');
            }
            return stk.empty();
        };

        vector<string> res;
        unordered_set<string> visited;
        visited.insert(s);
        deque<string> q;
        q.push_back(s);
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                string str = q.front();
                q.pop_front();
                if(is_valid(str)){
                    res.push_back(str);
                }
                for(int j = 0; j < str.length(); j++){
                    if(str[j] == '(' || str[j] == ')'){
                        string newStr = str.substr(0, j) + str.substr(j + 1);
                        if(visited.find(newStr) == visited.end()){
                            q.push_back(newStr);
                            visited.insert(newStr);
                        }
                    }
                }
            }
            if(!res.empty()) return res;
        }
        return {""};
    }
};