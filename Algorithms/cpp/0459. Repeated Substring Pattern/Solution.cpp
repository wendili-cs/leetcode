// https://leetcode-cn.com/problems/repeated-substring-pattern/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t = t.substr(1, t.length() - 2); // 掐头去尾
        if(t.find(s)==-1) return false;
        return true;
    }
};