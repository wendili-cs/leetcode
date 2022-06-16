// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long res1 = 0, res2 = 0; // res1 -> add pattern[0] at begin, res2 -> add pattern[1] at end
        int p1 = 0, p2 = 0;
        for(int i = 0; i < text.length(); i++){
            if(text[i] == pattern[1]){
                res1 += (p1 + 1);
                res2 += p1;
            }
            if(text[i] == pattern[0]) p1++;
        }
        res2 += p1;
        return res1>res2?res1:res2;
    }
};