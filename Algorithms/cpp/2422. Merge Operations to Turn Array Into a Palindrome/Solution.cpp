// https://leetcode.com/problems/merge-operations-to-turn-array-into-a-palindrome/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int l = 0, r = nums.size() - 1, res = 0;
        long lsum = nums[l], rsum = nums[r];
        while(l < r){
            if(lsum == rsum){
                l++;
                r--;
                lsum = nums[l];
                rsum = nums[r];
            }
            else if(lsum < rsum){
                l++;
                lsum += nums[l];
                res++;
            }
            else if(lsum > rsum){
                r--;
                rsum += nums[r];
                res++;
            }
        }
        return res;
    }
};