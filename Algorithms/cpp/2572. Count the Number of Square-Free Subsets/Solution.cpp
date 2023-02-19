// https://leetcode.com/problems/count-the-number-of-square-free-subsets/

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        int M = 1000000007, C = 1024;
        // dp[i][j]: the number of ways in the first i numbers under state j
        vector<vector<int>> dp(nums.size() + 1, vector<int>(C, 0));
        dp[0][0] = 1;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        vector<int> squares = {4,9,16,25};
        auto check_primes = [&](int x) -> int {
            // return a state of the primes, -1 if contains squares
            for(int i = 0; i < squares.size(); i++){
                if(x % squares[i] == 0) return -1;
            }
            int ret = 0;
            for(int i = 0; i < primes.size(); i++){
                if(x % primes[i] == 0) ret |= (1 << i);
            }
            return ret;
        };
        int num_ones = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[i + 1] = dp[i];
            if(nums[i] != 1){
                int state = check_primes(nums[i]);
                if(state != -1){
                    for(int j = 0; j < C; j++){
                        if(!(j & state)){
                            dp[i + 1][state|j] = (dp[i + 1][state|j] + dp[i][j])%M;
                        }
                        // cout << i + 1 << ", state: " << j << ", ways: " << dp[i + 1][j] << endl;
                    }
                }
            }
            else{
                num_ones++;
            }
        }
        int res = 0;
        for(int j = 0; j < C; j++){
            res = (res + dp[nums.size()][j])%M;
        }
        for(int i = 0; i < num_ones; i++){
            res = (2 * res)%M;
        }
        return res - 1;
    }
};