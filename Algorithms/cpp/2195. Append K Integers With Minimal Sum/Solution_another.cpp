// https://leetcode.com/problems/append-k-integers-with-minimal-sum/

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int cur = k; // cur是每次我们要新append的大于k的数字
        // append_sum是我们append的数字中，范围在(k, +infinity)的数字总和
        // num_sum是nums里面范围在[1,k]中的数字的总和
        long append_sum = 0, num_sum = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int num:s){
            if(num <= k){
                // [1,k]内num被占用了，所以要append的数字里面至少包含了cur（被挤兑出去的数字）
                do{ // 这里我们需要cur要至少做一个更新，因为每次append的数字要是unique的
                    cur++;
                }while(s.find(cur) != s.end()); // 如果cur在给定数组里面，重新更新cur直到它不在数组里面
                append_sum += cur;
                num_sum += num; // 记录一下总和
            }
        }
        // (long)k*(k + 1)/2 - num_sum：填满了[1, k]的范围，去掉nums里面已有的-->我们append数字中，范围在[1, k]的数字总和
        // append_sum：我们append的数字中，范围在(k, +infinity)的数字总和
        return (long)k*(k + 1)/2 - num_sum + append_sum;
    }
};