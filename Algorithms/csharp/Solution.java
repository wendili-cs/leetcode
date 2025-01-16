// https://leetcode.com/problems/bitwise-xor-of-all-pairings/

class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int res = 0;
        if(nums1.length % 2 != 0){
            for(int num:nums2){
                res ^= num;
            }
        }
        if(nums2.length % 2 != 0){
            for(int num:nums1){
                res ^= num;
            }
        }
        return res;
    }
}