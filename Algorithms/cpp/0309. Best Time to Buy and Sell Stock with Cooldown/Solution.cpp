// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// sell[i]表示截至第i天，最后一个操作是卖时的最大收益；
// buy[i]表示截至第i天，最后一个操作是买时的最大收益；
// cool[i]表示截至第i天，最后一个操作是冷冻期时的最大收益；
// 递推公式：
// sell[i] = max(buy[i-1]+prices[i], sell[i-1]) (第一项表示第i天卖出，第二项表示第i天冷冻)
// buy[i] = max(cool[i-1]-prices[i], buy[i-1]) （第一项表示第i天买进，第二项表示第i天冷冻）
// cool[i] = max(sell[i-1], buy[i-1], cool[i-1])

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        vector<int> sells(len, 0), buys(len, 0), cools(len, 0);
        buys[0] = -prices[0];
        for(int i = 1; i < len; i++){
            sells[i] = max(prices[i] + buys[i - 1], sells[i - 1]);
            buys[i] = max(cools[i - 1] - prices[i], buys[i - 1]);
            cools[i] = max(max(sells[i - 1], buys[i - 1]), cools[i - 1]);
        }
        return sells[len - 1];
    }
};