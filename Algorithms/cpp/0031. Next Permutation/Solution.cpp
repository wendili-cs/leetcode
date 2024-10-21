// https://leetcode-cn.com/problems/next-permutation/
// https://leetcode.com/problems/next-permutation/

// 具体地，我们这样描述该算法，对于长度为 n 的排列 a：
// 1. 首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i]<a[i+1]。这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。
// 2. 如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素 jj 满足 a[i]<a[j]。这样「较大数」即为 a[j]。
// 3. 交换 a[i] 与 a[j]，此时可以证明区间 [i+1,n) 必为降序。我们可以直接使用双指针反转区间 [i+1,n) 使其变为升序，而无需对该区间进行排序。

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2; 
        while(i >= 0 && nums[i] >= nums[i + 1]){ // 找到从右往左第一个i使得：nums[i] < nums[i + 1]
            i--;
        }
        if(i < 0){ // 这种情况比如[3, 2, 1]，只用reverse就可以结束
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = nums.size() - 1;
        while(nums[i] >= nums[j]){ // 找到从右往左第一个j使得：nums[i] < nums[j]
            j--;
        }
        // 此时类似从[3,6,4,2,1] (nums[i]=3, nums[j]=4)
        // 交换之后成为：[4,6,3,2,1]
        swap(nums[i], nums[j]);
        // nums[i + 1:]这部分逆转，从单调减变成单调增，即：[4,1,2,3,6]
        reverse(nums.begin() + i + 1, nums.end());
    }
};