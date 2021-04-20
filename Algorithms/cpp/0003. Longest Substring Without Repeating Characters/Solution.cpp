// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int longest = 0;
        for(int i = 0; i < len; i++){
            int count = 0;
            unordered_set<char> uset;
            for(int j = i; j < len; j++){
                auto iter = uset.find(s[j]);
                if(iter == uset.end()){
                    uset.emplace(s[j]);
                    count += 1;
                    longest = max(longest, count);
                    continue;
                }
                else{
                    break;
                }
            }
        }
        return longest;
    }
};