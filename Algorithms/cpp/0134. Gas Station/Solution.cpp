// https://leetcode-cn.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_tank = 0, cur_tank = 0, len = gas.size(), idx = 0;
        for(int i = 0; i < len; i++){
            sum_tank += gas[i] - cost[i];
            cur_tank += gas[i] - cost[i];
            if(cur_tank < 0){
                cur_tank = 0;
                idx = i + 1;
            }
        }
        return sum_tank >= 0? idx:-1;
    }
};