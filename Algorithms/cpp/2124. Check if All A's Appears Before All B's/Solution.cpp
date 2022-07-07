// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/

class Solution {
public:
    bool checkString(string s) {
        int l = 0, r = s.length() - 1;
        while(l < s.length() && s[l] == 'a') l++;
        while(r >= 0 && s[r] == 'b') r--;
        return l >= r;
    }
};