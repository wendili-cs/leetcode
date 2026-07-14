// https://leetcode.com/problems/minimum-total-cost-to-process-all-elements

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long sum = 0, M = 1000000007;
        for(int& num:nums) {
            sum += num;
        }
        long num_of_ops = sum/k - 1;
        if(sum % k != 0){
            // 未除尽的情况
             num_of_ops += 1;
        }
        num_of_ops %= M;
        return (1 + num_of_ops)*num_of_ops/2 % M;
    }
};