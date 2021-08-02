// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/submissions/

class Solution {
private:
    int partition(vector<int>& nums, int l, int r){
        int idx = rand()%(r - l + 1) + l, p, i , j;
        swap(nums[l], nums[idx]);
        for(p = nums[l], i = l + 1, j = l; i <= r; i++){
            if(nums[i] >= p) swap(nums[i], nums[++j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int l, int r, int k){
        int idx = partition(nums, l, r);
        if(idx + 1 == k) return nums[idx];
        else if(idx + 1 < k) return findKthLargest(nums, idx + 1, r, k);
        else return findKthLargest(nums, l, idx - 1, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }
};