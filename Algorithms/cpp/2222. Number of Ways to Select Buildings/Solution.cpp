// https://leetcode.com/problems/number-of-ways-to-select-buildings/

class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.length();
        vector<long> n0(n), n1(n), n01(n), n10(n), n101(n), n010(n);
        n0[0] = s[0]=='0';
        n1[0] = s[0]=='1';
        for(int i = 1; i < n; i++){
            n0[i] = n0[i - 1] + (s[i]=='0'?1:0);
            n1[i] = n1[i - 1] + (s[i]=='1'?1:0);
            n10[i] = n10[i - 1] + (s[i]=='0'?n1[i - 1]:0);
            n010[i] = n010[i - 1] + (s[i]=='0'?n01[i - 1]:0);
            n01[i] = n01[i - 1] + (s[i]=='1'?n0[i - 1]:0);
            n101[i] = n101[i - 1] + (s[i]=='1'?n10[i - 1]:0);
        }
        return n101.back() + n010.back();
    }
};