// https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> next(n), prev(n); // next/previous smaller element
        stack<pair<int, int>> stk; // increasing mono stack

        // find the next smaller element (index) of each element
        for(int i = 0; i < n; i++){
            while(!stk.empty() && stk.top().first > nums[i]){
                auto it = stk.top();
                stk.pop();
                next[it.second] = i - 1;
            }
            stk.push(make_pair(nums[i], i));
        }
        while(!stk.empty()){
            auto it = stk.top();
            stk.pop();
            next[it.second] = n - 1;
        }

        // find the previous smaller element (index) of each element
        for(int i = n - 1; i >= 0; i--){
            while(!stk.empty() && stk.top().first > nums[i]){
                auto it = stk.top();
                stk.pop();
                prev[it.second] = i + 1;
            }
            stk.push(make_pair(nums[i], i));
        }
        while(!stk.empty()){
            auto it = stk.top();
            stk.pop();
            prev[it.second] = 0;
        }

        // to see if element i satisfy the condition within [prev[i], next[i]]
        for(int i = 0; i < n; i++){
            int len = next[i] - prev[i] + 1;
            if(nums[i] > threshold/len){
                return len;
            }
        }
        return -1;
    }
};