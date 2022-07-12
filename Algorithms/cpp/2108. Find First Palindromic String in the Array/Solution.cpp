// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        auto is_palindromic = [&](string &s) -> bool {
            for(int i = 0; i < s.length()/2; i++){
                if(s[i] != s[s.length() - 1 - i]) return false;
            }
            return true;
        };
        for(string& word:words){
            if(is_palindromic(word)) return word;
        }
        return "";
    }
};