// https://leetcode.com/problems/sell-diminishing-valued-colored-balls/

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long total = 0, r_profit = 0, base = 0, ocnt = 0, r_orders = 0;
        sort(inventory.begin(), inventory.end());
        for(int& each:inventory){
            total += (long)(each+1)*(long)each/2;
            total %= 1000000007;
            r_orders += each;
        }
        r_orders -= orders;
        for(int i = 0; i < inventory.size() && r_orders > 0; i++){
            long remain_i = inventory.size() - i;
            if(r_orders < remain_i*(inventory[i] - base)){
                r_profit += (r_orders/remain_i)*(1 + 2*base + r_orders/remain_i)/2*remain_i;
                base += r_orders/remain_i;
                r_profit += (r_orders%remain_i)*(base + 1);
                r_profit %= 1000000007;
                break;
            }
            else{
                r_profit += (inventory[i] + base + 1)*(inventory[i] - base)/2*remain_i;
                r_orders -= remain_i*(inventory[i] - base);
                base = inventory[i];
                r_profit %= 1000000007;
            }
        }
        if(total - r_profit < 0) total += 1000000007;
        return (total - r_profit)%1000000007;
    }
};