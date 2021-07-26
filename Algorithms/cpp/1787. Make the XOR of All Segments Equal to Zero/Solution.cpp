// https://leetcode-cn.com/problems/make-the-xor-of-all-segments-equal-to-zero/

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int XOR_MAX = 1024, V_MAX = 3000;
        int len = nums.size();
        vector<vector<int> > dp(k, vector<int>(XOR_MAX, V_MAX));
        vector<int> dp_mins(k, V_MAX);
        for(int i = 0; i < k; i++){
            int cnt = len/k + (len%k > i?1:0); // 第i组有多少个数字
            map<int, int> cnter;
            for(int j = i; j < len; j += k) cnter[nums[j]]++;
            if(i == 0){
                for(int x = 0; x < XOR_MAX; x++){
                    dp[i][x] = cnt - cnter[x]; // 将除x以外的数替换所需次数
                    dp_mins[i] = min(dp_mins[i], dp[i][x]); // 记录最小值
                }
            }
            else{
                for(int x = 0; x < XOR_MAX; x++){
                    dp[i][x] = min(dp[i][x], dp_mins[i - 1] + cnt); // 不需要再减去本i中有多少个不用修改，当做是“初始化”而不是“选择性地修改值”
                    for(auto it:cnter) // 修改成it.first，其中已经有it.second不需要修改了
                        dp[i][x] = min(dp[i][x], dp[i - 1][x^it.first] + cnt - it.second);
                    dp_mins[i] = min(dp_mins[i], dp[i][x]);
                }
            }
        }
        return dp[k - 1][0];
    }
};