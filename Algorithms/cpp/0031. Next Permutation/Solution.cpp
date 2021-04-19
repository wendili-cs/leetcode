// https://leetcode-cn.com/problems/next-permutation/

// 具体地，我们这样描述该算法，对于长度为 nn 的排列 aa：
// 1. 首先从后向前查找第一个顺序对 (i,i+1)(i,i+1)，满足 a[i] < a[i+1]a[i]<a[i+1]。这样「较小数」即为 a[i]a[i]。此时 [i+1,n)[i+1,n) 必然是下降序列。
// 2. 如果找到了顺序对，那么在区间 [i+1,n)[i+1,n) 中从后向前查找第一个元素 jj 满足 a[i] < a[j]a[i]<a[j]。这样「较大数」即为 a[j]a[j]。
// 3. 交换 a[i]a[i] 与 a[j]a[j]，此时可以证明区间 [i+1,n)[i+1,n) 必为降序。我们可以直接使用双指针反转区间 [i+1,n)[i+1,n) 使其变为升序，而无需对该区间进行排序。

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int idx_1 = len - 2; // 找左边的较小的数
        while(idx_1 >= 0 && nums[idx_1] >= nums[idx_1 + 1]){
            idx_1--;
        }
        int idx_2 = len - 1; // 找右边第一个大于idx1的数
        if(idx_1 >= 0){
            while(nums[idx_2] <= nums[idx_1]){
                idx_2--;
            }
            swap(nums[idx_1], nums[idx_2]);
        }
        reverse(nums.begin() + idx_1 + 1, nums.end());
    }
};