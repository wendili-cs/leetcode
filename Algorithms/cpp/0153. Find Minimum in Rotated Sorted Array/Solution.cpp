// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

// 要点：两边一边是单调的，范围往左缩小不能跳着缩。往右可以
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = (l + r)/2;
            if(nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];

    }
};