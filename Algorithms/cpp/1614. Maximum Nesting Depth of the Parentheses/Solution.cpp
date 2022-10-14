// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int cur = 0, res = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                cur++;
                res = max(res, cur);
            }
            else if(s[i] == ')'){
                cur--;
            }
        }
        return res;
    }
};