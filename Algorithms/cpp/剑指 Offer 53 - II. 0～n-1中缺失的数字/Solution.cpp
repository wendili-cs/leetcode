// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.back() == nums.size() - 1) return nums.size();
        else if(nums[0] == 1) return 0;
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = (l + r)/2;
            if(nums[mid] == mid + 1) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};