// https://leetcode-cn.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char* s, const char* p){
        if(*p == 0){
            return !*s; // 空的正则项
        }
        bool is_match = *s && (*s == *p || *p == '.'); // 这个地方不能因为s是空的就直接返回！因为可能有s=""，p="a*"的情况
        if(*(p + 1) == '*'){
            return isMatch(s, p + 2) || is_match && isMatch(s + 1, p);
        }
        else{
            return is_match && isMatch(++s, ++p);
        }
    }
};