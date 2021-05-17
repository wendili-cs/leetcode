// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), l = 0, r = len - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > nums[r]){
                if(target >= nums[l] && target < nums[mid]) r = mid - 1; // target在left和midium之间，且这两点之间单调
                else l = mid + 1; // 其他情况
            }
            else{
                if(target <= nums[r] && target > nums[mid]) l = mid + 1; // target在mid和right之间，且这两点之间单调
                else r = mid - 1;
            }
        }
        return -1;
    }
};