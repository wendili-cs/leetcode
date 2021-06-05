// https://leetcode-cn.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int len = customers.size(), sum = 0, add = 0, max_add = add; // 不生气的增益
        for(int i = 0; i < len; i++) sum += grumpy[i]? 0:customers[i];
        for(int i = 0; i < len; i++){
            if(i >= minutes) add -= grumpy[i-minutes]? customers[i-minutes]:0;
            add += grumpy[i]? customers[i]:0;
            max_add = max(max_add, add);
        }
        return sum + max_add;
    }
};