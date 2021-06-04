// https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        // dp[i][j] = dp[i-1][j-1]+1 if nums1[i]==nums2[j] else 0
        int max_one = 0;
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(nums1[i - 1]==nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max_one = max(max_one, dp[i][j]);
                }
            }
        }
        return max_one;
    }
};