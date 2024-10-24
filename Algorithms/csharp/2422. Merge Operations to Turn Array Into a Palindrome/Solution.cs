// https://leetcode.com/problems/merge-operations-to-turn-array-into-a-palindrome/

public class Solution {
    public int MinimumOperations(int[] nums) {
        if(nums.Length == 1) return 0;
        int l = 0, r = nums.Length - 1, res = 0;
        long lsum = nums[l], rsum = nums[r];
        while(l < r){
            if(lsum == rsum){
                lsum = nums[++l];
                rsum = nums[--r];
            }
            else if(lsum < rsum){
                lsum += nums[++l];
                res++;
            }
            else if(lsum > rsum){
                rsum += nums[--r];
                res++;
            }
        }
        return res;
    }
}