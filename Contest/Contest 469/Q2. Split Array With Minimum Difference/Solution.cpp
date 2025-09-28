// https://leetcode.com/contest/weekly-contest-469/problems/split-array-with-minimum-difference/description/

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size(), lmax = 0, rmin = n - 1;
        while(lmax < n - 1) {
            if(nums[lmax] >= nums[lmax + 1]){
                // 非严格递增时终止
                break;
            }
            lmax++;
        }
        while(rmin > 0) {
            if(nums[rmin - 1] <= nums[rmin]){
                // 非严格递减时终止
                break;
            }
            rmin--;
        }
        // i有效的取值需要：大于rmin && 小于lmax
        if(lmax + 1 < rmin) return -1;
        long left = 0, right = 0, res = 10000000000;
        for(int & num:nums) right += num;
        for(int i = 0; i <= lmax ; i++){
            left += nums[i];
            right -= nums[i];
            if(i >= rmin - 1) {
                // 只有
                res = min(res, abs(left - right));
            }
        }
        return res;
    }
};©leetcode