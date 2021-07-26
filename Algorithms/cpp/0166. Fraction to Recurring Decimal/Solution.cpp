// https://leetcode-cn.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long a = abs((long)numerator), b = abs((long)denominator);
        string res;
        if((numerator < 0 && denominator > 0)||(numerator > 0 && denominator < 0)) res += "-";
        res += to_string(a/b) + (a%b==0?"":".");
        map<int, int> m;
        while((a = (a%b)*10) > 0 && m.find(a)==m.end()){
            m[a] = res.length();
            res += to_string(a/b);
            // a = (a%b)*10;
        }
        if(a != 0){
            res.insert(m[a], "(");
            res += ")";
        }
        return res;
    }
};