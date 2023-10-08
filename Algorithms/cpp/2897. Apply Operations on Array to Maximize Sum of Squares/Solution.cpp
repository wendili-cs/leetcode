// https://leetcode.com/contest/weekly-contest-366/problems/apply-operations-on-array-to-maximize-sum-of-squares/

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32);
        int M = 1000000007;
        for(int num:nums){
            int cur = 0;
            while(num > 0){
                if(num&1) bits[cur]++;
                num >>= 1;
                cur++;
            }
        }
        long res = 0;
        for(int i = 0; i < k; i++){
            long x = 0;
            for(int j = 31; j >= 0; j--){
                x <<= 1;
                if(bits[j] > 0){
                    x++;
                    bits[j]--;
                }
            }
            res += (x*x)%M;
        }
        return res%M;
    }
};