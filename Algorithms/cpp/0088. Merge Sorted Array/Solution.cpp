// https://leetcode-cn.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx_1 = m - 1, idx_2 = n - 1, cur;
        int tail_idx = nums1.size() - 1;
        while(idx_1 >= 0 || idx_2 >= 0){
            if(idx_1 < 0){
                cur = nums2[idx_2--];
            }
            else if(idx_2 < 0){
                cur = nums1[idx_1--];
            }
            else{
                cur = nums1[idx_1] > nums2[idx_2]? nums1[idx_1--]:nums2[idx_2--];
            }
            nums1[tail_idx--] = cur;
        }
    }
};