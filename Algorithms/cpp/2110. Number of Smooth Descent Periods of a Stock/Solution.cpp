// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long res = 0;
        int pre = 0, i; // begin of the descent period
        for(i = 1; i < prices.size(); i++){
            if(pre != i && prices[i] != prices[i - 1] - 1){
                res += (long)(i - pre)*(i - pre + 1)/2;
                pre = i;
            }
        }
        res += (long)(i - pre)*(i - pre + 1)/2;
        return res;
    }
};