// https://leetcode-cn.com/problems/multiply-strings/


class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        if(num1 == "0" || num2 == "0") return "0";
        string res;
        int adding = 0, remainer, sum;

        for(int T = len1 + len2 - 2; T >= 0; T--){
            sum = adding;
            adding = 0;

            for(int i = len1 - 1; i >= 0; i--){
                int j = T - i;
                if(j < 0 || j > len2 - 1) continue;
                int num1_i = num1[i] - '0';
                int num2_j = num2[j] - '0';
                sum += num1_i * num2_j;
            }
            adding = sum / 10;
            remainer = sum % 10;
            res = (char)(remainer + '0') + res;
        }
        if(adding != 0) res = (char)(adding + '0') + res;
        return res;
    }
};