// https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 0, p3 = 0, p5 = 0; 
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            // next ugly number is within m2, m3, m5
            int m2 = dp[p2]*2;
            int m3 = dp[p3]*3;
            int m5 = dp[p5]*5;
            dp[i] = min(m2, min(m3, m5));
            
            // if we already add the candidate, move the pointer to next element
            if(dp[i] == m2) p2++;
            if(dp[i] == m3) p3++;
            if(dp[i] == m5) p5++;
        }
        return dp.back();
    }
};