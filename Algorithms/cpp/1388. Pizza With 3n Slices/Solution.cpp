// https://leetcode-cn.com/problems/pizza-with-3n-slices/

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        // dp[i][j]表示在前i个数中选择了j个不相邻的数
        // 所以dp[i][j] 就是“不取第i个，在i-1个里面取j个”和“取第i个，在i-2个之前取j-1个”两种选择之间大的那个
        // dp[i][j] = max(dp[i-1][j], dp[i-2][j-1]+arr[i-1])
        auto solve = [&](vector<int> &arr) -> int {
            int len = arr.size();
            vector<vector<int> > dp(len + 1, vector<int>((len + 1)/3 + 1, 0)); // 这里len + 1是总长度，因为实际掐头或者去尾了
            for(int i = 1; i <= len; i++){
                for(int j = 1; j <= (len + 1)/3; j++){
                    dp[i][j] = max(dp[i - 1][j], (i<2?0:dp[i - 2][j - 1]) + arr[i - 1]);
                }
            }
            return dp.back().back();
        };
        vector<int> v1(slices.begin(), slices.end() - 1), v2(slices.begin() + 1, slices.end());
        return max(solve(v1), solve(v2));
    }
};