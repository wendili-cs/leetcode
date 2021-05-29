// https://leetcode-cn.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> costs(cost.size() + 1);
        costs[0] = cost[0];
        costs[1] = cost[1];
        if(cost.size() <= 2) return *min_element(cost.begin(), cost.end()); 
        for(int i = 2; i <= cost.size(); i++){
            int temp = i == cost.size()? 0:cost[i];
            costs[i] = min(costs[i - 1], costs[i - 2]) + temp;
        }
        return costs.back();
    }
};