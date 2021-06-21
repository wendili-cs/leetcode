// https://leetcode-cn.com/problems/wildcard-matching/

// 仿制#10的递归，超时了...
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char* s, const char* p){
        if(*p == 0){
            return !*s; // 空的正则项
        }
        bool is_match = *s && (*s == *p || *p == '?' || *p == '*');
        if(*p == '*'){
            if(*s == 0 && *(p + 1) == 0) return true; // 空的字符串对应最后一个空的*
            return isMatch(s, p + 1) || is_match && isMatch(s + 1, p);
        }
        else{
            return is_match && isMatch(++s, ++p);
        }
    }
};