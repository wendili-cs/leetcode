// https://leetcode-cn.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        auto cnt_pali = [&](int l, int r) -> void {
            while(l >=0 && r < s.length() && s[l] == s[r]){
                res += 1;
                l--;
                r++;
            }
        };
        for(int i = 0; i < s.length(); i++){
            cnt_pali(i, i);
            cnt_pali(i, i + 1);
        }
        return res;
    }
};