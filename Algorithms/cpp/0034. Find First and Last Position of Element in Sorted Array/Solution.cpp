// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 1) return nums[0]==target? vector<int>(2, 0):vector<int>(2, -1);
        else if(len == 0) return {-1, -1};
        int l = 0, r = len - 1, mid = (r + l)/2;
        int idx_l, idx_r;
        bool found = false;
        while(r >= l){
            if(nums[mid] >= target){
                if(nums[mid] == target) found = true;
                r = mid - 1;
            }
            else l = mid + 1;
            mid = (l + r)/2;
        }
        if(!found) return{-1, -1};
        if(nums[mid] == target) idx_l = mid;
        else idx_l = mid + 1;
        l = 0, r = len - 1, mid = (r + l)/2;
        while(r >= l){
            if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
            mid = (l + r)/2;
        }
        if(nums[mid] == target) idx_r = mid;
        else idx_r = mid - 1;
        return {idx_l, idx_r};
    }
};