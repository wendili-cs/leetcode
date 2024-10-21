// https://leetcode.com/problems/append-k-integers-with-minimal-sum/

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // num_sum是nums里面范围在[1,k]中的数字的总和
        sort(nums.begin(), nums.end());
        long num_sum = 0;
        unordered_set<int> s;
        for(int num:nums){
            // [1,k]内num被占用了，所以要append的数字范围扩容为[1,k+1]
            if(s.find(num) == s.end() && num <= k){
                num_sum += num;
                k++;
            }
            s.insert(num); // 再次遇到num没差别，不用管
        }
        // 我们最后填满了[1, k]的范围，所以总和是k*(k+1)/2。但是num_sum这部分和不是我们填进去的，去掉它
        return (long)k*(k + 1)/2 - num_sum;
    }
};