// https://leetcode.com/problems/minimum-cost-to-set-cooking-time/

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        auto cost = [&](int mm, int ss) -> int {
            if(mm > 99 || ss > 99 || mm < 0 || ss < 0) return INT_MAX; // invalid input
            vector<int> nums;
            while(ss > 0){
                nums.push_back(ss%10);
                ss /= 10;
            }
            while(nums.size() < 2 && mm) nums.push_back(0);
            while(mm > 0){
                nums.push_back(mm%10);
                mm /= 10;
            }
            int cur = startAt, cost = 0;
            for(int i = nums.size() - 1; i >= 0; i--){
                if(cur != nums[i]){
                    cost += moveCost;
                    cur = nums[i];
                }
                cost += pushCost;
            }
            return cost;
        };
        return min(cost(targetSeconds/60, targetSeconds%60), cost(targetSeconds/60 - 1, targetSeconds%60 + 60));
    }
};