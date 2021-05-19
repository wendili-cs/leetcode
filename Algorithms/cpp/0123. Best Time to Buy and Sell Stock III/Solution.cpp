// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/

// 对于任意一天考虑四个变量:
// buy1: 在该天第一次买入股票可获得的最大收益 
// sell1: 在该天第一次卖出股票可获得的最大收益
// but2: 在该天第二次买入股票可获得的最大收益
// sell2: 在该天第二次卖出股票可获得的最大收益
// 分别对四个变量进行相应的更新, 最后sell2就是最大
// 收益值(sell2 >= sell1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        int buy1 = INT_MAX, sell1 = 0, buy2 = INT_MAX, sell2 = 0;
        for(const int& p:prices){
            buy1 = min(buy1, p);
            sell1 = max(sell1, p - buy1);
            buy2 = min(buy2, p - sell1);
            sell2 = max(sell2, p - buy2);
        }
        return sell2;
    }
};