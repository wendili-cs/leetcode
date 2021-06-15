// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0 || prices.size() <= 1) return 0;
        vector<int> buys(k, INT_MIN), sells(k, 0);
        for(const int& p:prices){
            for(int j = 0; j < k; j++){
                int prev_sell = j==0?0:sells[j - 1];
                buys[j] = max(prev_sell - p, buys[j]);
                sells[j] = max(p + buys[j], sells[j]);
            }
        }
        return sells.back();
    }
};