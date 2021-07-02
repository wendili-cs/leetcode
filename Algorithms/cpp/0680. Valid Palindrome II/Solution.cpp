// https://leetcode-cn.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool validPalindrome(string s) {
        auto is_palidrome = [](string str) -> bool {
            int i = 0, j = str.length() - 1;
            while(i < j){
                if(str[i]!=str[j]) return false;
                i++;
                j--;
            }
            return true;
        };
        if(is_palidrome(s)) return true;
        int l = 0, r = s.length() - 1;
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else{
                return is_palidrome(s.substr(l, r - l)) || is_palidrome(s.substr(l + 1, r - l));
            }
        }
        return true;
    }
};