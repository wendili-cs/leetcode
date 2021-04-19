// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int min_val = prices[0], max_profit = 0;
        for(int i = 0; i < len; i++){
            if(min_val > prices[i]){
                min_val = prices[i];
            }
            max_profit = max(prices[i] - min_val, max_profit);
        }
        return max_profit;
    }
};