// https://leetcode.com/problems/make-array-non-decreasing-or-non-increasing/


class Solution {
public:
    int convertArray(vector<int>& nums) {
        int n = nums.size(), res;
        auto calc_num_ops = [&]() -> int {
            int ret = 0;
            priority_queue<int> pq;
            for(int i = 0; i < n; i++){
                if(!pq.empty() && pq.top() > nums[i]){
                    ret += pq.top() - nums[i];
                    pq.pop();
                    pq.push(nums[i]);
                }
                pq.push(nums[i]);
            }
            return ret;
        };
        res = calc_num_ops();
        for(int i = 0; i < n; i++) nums[i] = -nums[i];
        res = min(res, calc_num_ops());
        return res;
    }
};