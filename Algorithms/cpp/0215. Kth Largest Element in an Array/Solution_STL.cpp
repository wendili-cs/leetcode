// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(const auto& num:nums){
            pq.push(num);
        }
        for(int i = 0; i < k - 1; i++){
            pq.pop();
        }
        return pq.top();
    }
};