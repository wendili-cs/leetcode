// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        for(int i = 0; i < n - m + 1; i++){
            if(haystack[i] == needle[0]){
                int idx = 0;
                while(idx < m && needle[idx] == haystack[i + idx]) idx++;
                if(idx == m) return i;
            }
        }
        return -1;
    }
};