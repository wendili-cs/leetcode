// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Solution: https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/5492177/easy-and-simple-c-approach-binary-search

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int X = 10000000; // max/min value
        if(nums1.size() > nums2.size()) swap(nums1, nums2);
        // m < n
        int m = nums1.size(), n = nums2.size(), low1 = 0, high1 = m, mid1, mid2;
        while(low1 <= high1){
            mid1 = (low1 + high1)/2;
            mid2 = (m + n + 1)/2 - mid1;
            // mid1 + mid2 = (m + n + 1)/2

            // l1 and r1 are the elements just to the left and right of mid1 in nums1, respectively.
            // l2 and r2 are the elements just to the left and right of mid2 in nums2, respectively.
            int l1 = -X, l2 = -X, r1 = X, r2 = X; // init
            if(mid1 < m) r1 = nums1[mid1];
            if(mid2 < n) r2 = nums2[mid2];
            if(mid1 > 0) l1 = nums1[mid1 - 1];
            if(mid2 > 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){ // the condition that the partition is correct
                if((m + n)%2 == 0){
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else{
                    return max(l1, l2);
                }
            }
            else if(l1 > r2) {
                high1 = mid1 - 1;
            }
            else if(l2 > r1) {
                low1 = mid1 + 1;
            }
        }
        return 0.0;
    }
};