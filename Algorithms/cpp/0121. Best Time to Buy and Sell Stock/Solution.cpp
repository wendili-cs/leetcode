// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int max_profit = 0, lowest_price = prices[0];
        for(int i = 1; i < prices.size(); i++){
            max_profit = max(max_profit, prices[i] - lowest_price);
            lowest_price = min(lowest_price, prices[i]);
        }
        return max_profit;
    }
};