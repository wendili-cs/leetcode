// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size(), l = 0, r = len - 1;
        while(l < r){
            if(l < len && nums[l]&1) l++;
            else if(r >=0 && !(nums[r]&1)) r--;
            else swap(nums[l], nums[r]);
        }
        return nums;
    }
};