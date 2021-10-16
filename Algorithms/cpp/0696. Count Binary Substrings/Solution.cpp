// https://leetcode.com/problems/count-binary-substrings/

class Solution {
public:
    int countBinarySubstrings(string s) {
        set<pair<int, bool>> st;
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            int j = i;
            while(j < s.length() && s[j] == s[i]) j++;
            int k = j;
            while(k < s.length() && s[k] == s[j]) k++;
            res += min(k - j, j - i);
            i = j - 1;
        }
        return res;
    }
};