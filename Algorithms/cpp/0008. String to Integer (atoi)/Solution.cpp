// https://leetcode-cn.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        bool sign = 1;
        bool begin_proc = false;
        for(const auto c:s){
            if(!begin_proc){
                if(c == '+'){
                    sign = 1;
                    begin_proc = true;
                }
                else if(c == '-'){
                    sign = 0;
                    begin_proc = true;
                }
                else if('9' >= c && c >= '0'){
                    int temp = c - '0';
                    res = temp;
                    begin_proc = true;
                }
                else if(c != ' '){
                    return 0;
                }
                continue;
            }
            if(c < '0' || c > '9'){
                break;
            }
            else{
                int temp = c - '0';
                res = res * 10 + temp;
                if(sign && res > INT_MAX) return INT_MAX;
                if(!sign && -res < INT_MIN) return INT_MIN;
            }
            begin_proc = true;
        }
        if(sign){
            return res > INT_MAX? INT_MAX:res;
        }
        else{
            return -res < INT_MIN? INT_MIN:-res;
        }
    }
};