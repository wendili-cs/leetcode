// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for(int i = 0; i < 2*n; i++){
            int idx = i%n;
            while(!stk.empty() && nums[stk.top()] < nums[idx]){
                res[stk.top()] = nums[idx];
                stk.pop();
            }
            stk.push(idx);
        }
        return res;
    }
};