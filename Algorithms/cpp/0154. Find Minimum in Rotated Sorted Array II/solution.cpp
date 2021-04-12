// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l_ptr = 0, r_ptr = nums.size() - 1;
        while(l_ptr < r_ptr){
            int p_ptr = l_ptr + (r_ptr - l_ptr)/2;
            if(nums[p_ptr] > nums[r_ptr]){
                l_ptr = p_ptr + 1;
            }
            else if(nums[p_ptr] < nums[r_ptr]){
                r_ptr = p_ptr;
            }
            else{
                r_ptr--;
            }
        }
        return nums[l_ptr];
    }
};