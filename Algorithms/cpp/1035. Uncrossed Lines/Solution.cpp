// https://leetcode-cn.com/problems/uncrossed-lines/

// 我们设函数f(x,y)标识A的前x个数字和B的前y个数字，能绘制出的最大连接数。假设A、B都是从下标1开始。
// 则f(0,y)=0,f(x,0)=0;
// 情况1：
// 如果A[x]!=B[y]，那么f(x,y)=max(f(x-1,y),f(x,y-1));
// 情况2：
// 如果A[x]==B[y]，那么f(x,y)=f(x-1,y-1)+1;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp.back().back();
    }
};