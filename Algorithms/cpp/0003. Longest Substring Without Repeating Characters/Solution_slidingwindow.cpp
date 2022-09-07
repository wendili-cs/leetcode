// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int res = 0, cur = 0;
        for(int i = 0, j = 0; j < s.length(); j++){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]] + 1);
            }
            res = max(res, j - i + 1);
            mp[s[j]] = j;
        }
        return res;
    }
};