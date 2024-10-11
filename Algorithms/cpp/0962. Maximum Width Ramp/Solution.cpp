// https://leetcode.com/problems/maximum-width-ramp/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stk;
        for(int i = 0; i < nums.size(); i++){
            // maintain a decreasing monotonic stack without poping
            if(stk.empty() || nums[stk.top()] > nums[i]){
                stk.push(i);
            }
        }
        int res = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            // find all the cases where nums[stk.top()] < nums[i] && stk.top() < i
            while(!stk.empty() && nums[i] >= nums[stk.top()]){
                res = max(res, i - stk.top());
                stk.pop();
            }
        }
        return res;
    }
};