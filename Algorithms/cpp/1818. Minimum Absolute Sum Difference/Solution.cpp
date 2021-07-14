// https://leetcode-cn.com/problems/minimum-absolute-sum-difference/

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num1_c = nums1;
        sort(num1_c.begin(), num1_c.end());
        long sum = 0, max_minus = 0;
        for(int i = 0; i < nums1.size(); i++){
            long diff = abs(nums1[i] - nums2[i]);
            sum += diff;
            if(diff == 0) continue;
            auto p = lower_bound(num1_c.begin(), num1_c.end(), nums2[i]);
            if(p != num1_c.end()) max_minus = max(max_minus, diff - abs(*p - nums2[i]));
            if(p != num1_c.begin()) max_minus = max(max_minus, diff - abs(*(p - 1) - nums2[i]));
        }
        return (sum - max_minus) % 1000000007;
    }
};