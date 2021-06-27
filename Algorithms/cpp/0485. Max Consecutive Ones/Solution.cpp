// https://leetcode-cn.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, max_cnt = 0;
        for(auto& num:nums){
            if(num == 1){
                cnt++;
                max_cnt = max(max_cnt, cnt);
            }
            else cnt = 0;
        }
        return max_cnt;
    }
};