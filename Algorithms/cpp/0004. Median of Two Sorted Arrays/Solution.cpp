// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1_len = nums1.size(), l2_len = nums2.size();

        auto getKthElement = [&](int k) -> int {
            int idx_1 = 0, idx_2 = 0;
            while(true){
                if(idx_1 == l1_len){
                    return nums2[idx_2 + k - 1]; // nums1 数组耗尽的情况
                }
                else if(idx_2 == l2_len){
                    return nums1[idx_1 + k - 1];
                }
                else if(k == 1){
                    return min(nums1[idx_1], nums2[idx_2]);
                }
                int idx_1_temp = min(idx_1 + k/2 - 1, l1_len - 1);
                int idx_2_temp = min(idx_2 + k/2 - 1, l2_len - 1);
                    
                if(nums1[idx_1_temp] >= nums2[idx_2_temp]){
                    k = k - (idx_2_temp - idx_2 + 1);
                    idx_2 = idx_2_temp + 1;
                }
                else{
                    k = k - (idx_1_temp - idx_1 + 1);
                    idx_1 = idx_1_temp + 1;
                }
            }
        };

        if((l1_len + l2_len)&1){
            return getKthElement((l1_len + l2_len + 1)/2);
        }
        else{
            return (getKthElement((l1_len + l2_len)/2 + 1) + getKthElement((l1_len + l2_len)/2))*0.5;
        }
    }
};