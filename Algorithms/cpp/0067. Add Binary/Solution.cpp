// https://leetcode-cn.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        int i1 = a.length() - 1, i2 = b.length() - 1;
        int next = 0;
        string res = "";
        while(i1 >= 0|| i2 >= 0 || next){
            int ai = i1 >= 0? a[i1--] - '0':0, bi = i2 >= 0? b[i2--] - '0':0;
            char c = (ai + bi + next)%2 + '0';
            next = ai + bi + next > 1;
            res = c + res;
        }
        return res;
    }
};