// https://leetcode.com/problems/number-of-wonderful-substrings/

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long res = 0;
        vector<int> dp = vector<int>(1024, 0); // dp[i] refers to how many substrings with all even counters
        dp[0] = 1;
        int state = 0;
        for(char& c:word){
            int idx = c - 'a';
            state ^= (1 << idx);
            res += dp[state];
            for(int i = 0; i < 10; i++){
                int near_state = state ^ (1 << i);
                res += dp[near_state];
            }
            dp[state]++;
        }
        return res;
    }
};