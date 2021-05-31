// https://leetcode-cn.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        string S = "";
        int ascii_d = 'a' - 'A';
        for(const int& c:s){
            if('A' <= c && c <= 'Z') S += c + ascii_d;
            else if(('a' <= c && c <= 'z')||(isdigit(c))) S += c;
        }
        int len = S.length();
        for(int i = 0; i < len; i++){
            if(S[i] != S[len - 1 - i]) return false;
        }
        return true;
    }
};