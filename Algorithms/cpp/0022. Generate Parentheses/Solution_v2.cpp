// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        function<void(int, int, int)> backtrack;
        vector<string> res;
        string temp;
        backtrack = [&](int i, int l, int r) -> void {
            if(i == 2*n) {
                res.push_back(temp);
                return;
            }
            if(l > 0) {
                temp.push_back('(');
                backtrack(i + 1, l - 1, r);
                temp.pop_back();
            }
            if(r > 0 && r > l) {
                temp.push_back(')');
                backtrack(i + 1, l, r - 1);
                temp.pop_back();
            }
        };
        backtrack(0, n, n);
        return res;
    }
};