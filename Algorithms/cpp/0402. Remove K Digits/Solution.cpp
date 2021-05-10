// https://leetcode-cn.com/problems/remove-k-digits/
// 从左到右，找第一个比后面大的字符，删除，清零，k次扫描。

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.length()) return "0";
        for(int i = 0; i < k; i++){
            for(int j = 0; j < num.length(); j++){
                if(j == num.length() - 1 || num[j] > num[j + 1]){
                    num.erase(j, 1);
                    while(num.length() > 1 && num[0] == '0') num.erase(0, 1);
                    break;
                }
                
            }
        }
        return num == ""? "0":num;
    }
};