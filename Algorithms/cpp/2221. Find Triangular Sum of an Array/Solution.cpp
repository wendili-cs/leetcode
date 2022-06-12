// https://leetcode.com/problems/find-triangular-sum-of-an-array/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> w(n);
        w[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = i; j >= 1; j--){
                w[j] = (w[j] + w[j - 1])%10;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = (res + w[i]*nums[i])%10;
        }
        return res;
    }
};