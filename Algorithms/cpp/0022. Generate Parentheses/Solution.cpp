// https://leetcode-cn.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp_list;

        function<void(int, int)> recurr;
        recurr = [&](int l, int r) -> void {
            if(l == n && r == n){
                res.push_back(temp_list);
                return;
            }
            if(l < n){
                temp_list += '(';
                recurr(l + 1, r);
                temp_list.pop_back();
            }
            if(r < l){
                temp_list += ')';
                recurr(l, r + 1);
                temp_list.pop_back();
            }
        };
        recurr(0, 0);
        return res;
    }
};