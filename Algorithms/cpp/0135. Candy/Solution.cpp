// https://leetcode-cn.com/problems/candy/
// 1. score[i] > score[i - 1], candy[i] = candy[i] + 1
// 2. score[i] > score[i + 1], candy[i] = candy[i + 1] + 1

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len == 1) return 1;
        vector<int> candies(len, 1);
        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
            else candies[i] = 1;
        }
        for(int i = len - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]) candies[i] = max(candies[i + 1] + 1, candies[i]);
        }
        int sum = 0;
        for(const auto& t:candies){
            sum += t;
        }
        return sum;
    }
};