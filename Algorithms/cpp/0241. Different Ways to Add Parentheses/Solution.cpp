// https://leetcode-cn.com/problems/different-ways-to-add-parentheses/

// 递归分治，可以用DP优化
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int> > dp;
        function<vector<int>(string)> parse;
        parse = [&](string expr) -> vector<int> {
            if(dp.find(expr) != dp.end()) return dp[expr];
            vector<int> ret;
            for(int i = 0; i < expr.length(); i++){
                if(expr[i] == '+'||expr[i] == '-'||expr[i] == '*'){
                    vector<int> ret1 = parse(expr.substr(0, i)), ret2 = parse(expr.substr(i + 1));
                    for(auto r1:ret1){
                        for(auto r2:ret2){
                            if(expr[i] == '+') ret.push_back(r1 + r2);
                            else if(expr[i] == '-') ret.push_back(r1 - r2);
                            else if(expr[i] == '*') ret.push_back(r1*r2);
                        }
                    }
                }
            }
            if(ret.empty()) ret.push_back(stoi(expr));
            dp[expr] = ret;
            return dp[expr];
        };
        return parse(expression);
    }
};