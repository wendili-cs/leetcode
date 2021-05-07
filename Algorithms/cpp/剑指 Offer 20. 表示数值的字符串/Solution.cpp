// https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/

class Solution {
public:
    bool isNumber(string s) {
        bool allow_sign = true, allow_dot = true, allow_e = true, is_digit = false;
        while(s[0] == ' '){
            if(s.length() > 0) s = s.substr(1);
            else return false;
        }
        int len = s.length();
        while(len > 0 && s[len - 1] == ' '){
            s = s.substr(0, len - 1);
            len = s.length();
        }
        if(s == "."||s == "") return false; // 是不是不合格的小数

        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c == 'E'||c == 'e'){
                if(!allow_e||i == 0||s.substr(0, i) == "."||!is_digit) return false;
                allow_e = false;
                allow_dot = false;
                if(i + 1 >= s.length()) return false;
                else if((s[i + 1] == '+'||s[i + 1] == '-')){
                    if(i + 2 >= s.length()) return false;
                    i++;
                }
            }
            else if(c == '.'){
                if(!allow_dot) return false;
                allow_dot = false;
            }
            else if(isdigit(c)){
                is_digit = true;
            }
            else if(c == '+'||c=='-'){
                if(i != 0) return false;
            }
            else{
                return false;
            }

        }
        return is_digit;
    }
};