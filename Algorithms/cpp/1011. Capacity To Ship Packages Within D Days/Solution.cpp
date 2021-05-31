// https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = accumulate(weights.begin(), weights.end(), 0), l = *max_element(weights.begin(), weights.end());
        while(l < r){
            int mid = (l + r)/2, temp = 0, day = 1;
            for(const int& w:weights){
                if(temp + w > mid){
                    temp = w;
                    day++;
                }
                else{
                    temp += w;
                }
            }
            if(day > days) l = mid + 1; // 容量太小
            else r = mid; // 可能刚好所以不能mid - 1
        }
        return l;
    }
};