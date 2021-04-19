https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, len = prices.size();
        if(len == 1){
            return 0;
        }
        for(int i = 1; i < len; i++){
            if(prices[i] >= prices[i - 1]){
                sum = sum + prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
};