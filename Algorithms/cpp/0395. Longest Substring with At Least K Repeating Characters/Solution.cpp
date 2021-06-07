// https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/

// 1. 先滑到不满足k的范围[0, i]
//     1.1 若滑到了尾部，直接返回长度
//     1.2 若滑到中间，递归查找[0,i]和[i+x,-1]区间（x是不符合的部分）
// 2. 返回两者中最大的

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k == 1) return s.length();
        if(s.empty() || s.length() < k) return 0;

        vector<int> cnt(26, 0);
        for(char c:s) cnt[c - 'a']++;

        int i = 0;
        while(i < s.length() && cnt[s[i] - 'a'] >= k) i++;
        if(i == s.length()) return s.length();

        int l = longestSubstring(s.substr(0, i), k);
        while(i < s.length() && cnt[s[i] - 'a'] < k) i++;
        int r = longestSubstring(s.substr(i), k);
        return max(l, r);
    }
};