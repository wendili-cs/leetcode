// https://leetcode-cn.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l, r = 0;
        for(l = 0; l < s.length(); l++){
            while(r < t.length() && t[r] != s[l]) r++;
            if(r == t.length()) break;
            else r++;
        }
        return l == s.length();
    }
};