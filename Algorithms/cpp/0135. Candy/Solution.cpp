// https://leetcode-cn.com/problems/candy/
// 1. score[i] > score[i - 1], candy[i] = candy[i] + 1
// 2. score[i] > score[i + 1], candy[i] = candy[i + 1] + 1

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;
        vector<int> candies(n);
        for(int i = 0; i < n; i++){
            // 如果我(i)比我前面的大，我的candy比它多1
            if(i > 0 && ratings[i - 1] < ratings[i]) candies[i] = candies[i - 1] + 1; 
            else candies[i] = 1; // 否则给最少值（第一个也给最小值）
        }
        for(int i = n - 2; i >= 0; i--){
            // 如果我(i)比我后面的大，我的candy要保证比它多1
            if(ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        return accumulate(candies.begin(), candies.end(), 0); // 计算总和就可以
    }
};