// https://leetcode-cn.com/problems/sort-an-array/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto partition = [&](int l, int r) -> int {
            swap(nums[l], nums[(l + r)/2]);
            int pivot = nums[l];
            while(l < r){
                while(l < r && nums[r] >= pivot) r--;
                nums[l] = nums[r];
                while(l < r && nums[l] <= pivot) l++;
                nums[r] = nums[l];
            }
            nums[l] = pivot;
            return l;
        };
        function<void(int, int)> qs;
        qs = [&](int l, int r) -> void {
            if(l < r){
                int p_idx = partition(l, r);
                qs(l, p_idx - 1);
                qs(p_idx + 1, r);
            }
        };
        qs(0, nums.size() - 1);
        return nums;
    }
};