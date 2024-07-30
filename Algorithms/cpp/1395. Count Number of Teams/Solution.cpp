// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), inc_cnt = 0, dec_cnt = 0;
        vector<int> dp1(n, 0), dp2(n, 0);
        // dp1[i] = number of ratings less than rating[i]
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(rating[i] > rating[j]){
                    dp1[i]++;
                    inc_cnt += dp1[j];
                }
                else if(rating[i] < rating[j]){
                    dp2[i]++;
                    dec_cnt += dp2[j];
                }
            }
        }
        return inc_cnt + dec_cnt;
    }
};