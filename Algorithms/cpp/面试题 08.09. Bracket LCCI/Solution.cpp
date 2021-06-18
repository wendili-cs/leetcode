// https://leetcode-cn.com/problems/bracket-lcci/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        stack<char> stk;
        function<void(int, int)> recur;
        recur = [&](int l, int r) -> void {
            if(l == n){
                res.push_back(temp + string(l - r, ')'));
                return;
            }
            if(l > r){
                temp += ')';
                recur(l, r + 1);
                temp.pop_back();
            }
            temp += '(';
            recur(l + 1, r);
            temp.pop_back();
        };
        recur(0, 0);
        return res;
    }
};