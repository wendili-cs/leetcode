// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp;
        function<void(int, int, int)> backtrack;
        backtrack = [&](int pos, int x, int y) -> void {
            // pos < n*2, x是正括号个数, y反括号个数
            if(pos == n*2){
                res.push_back(tmp);
                return;
            }
            if(x > y){
                tmp.push_back(')');
                backtrack(pos + 1, x, y + 1);
                tmp.pop_back();
            }
            if(x < n){
                tmp.push_back('(');
                backtrack(pos + 1, x + 1, y);
                tmp.pop_back();
            }
        };
        backtrack(0, 0, 0);
        return res;
    }
};