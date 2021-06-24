// https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

// 思路：维护两个上升、下降的队列，用滑动窗口每次只用比较单调队列的差就行
// 1. 保证队列内的元素在滑动指针之内
// 2. 保证队列单调，每次放入新的r之前，弹出不符合的
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0, len = nums.size();
        if(len <= 1) return len;
        deque<int> qmax, qmin;
        int l = 0, r = 0;
        while(r < len){
            while(!qmax.empty() && nums[qmax.back()] >= nums[r]) qmax.pop_back();
            while(!qmin.empty() && nums[qmin.back()] <= nums[r]) qmin.pop_back();
            qmax.push_back(r);
            qmin.push_back(r);
            
            while(abs(nums[qmax.front()] - nums[qmin.front()]) > limit){
                l++;
                while(!qmax.empty() && qmax.front() < l) qmax.pop_front();
                while(!qmin.empty() && qmin.front() < l) qmin.pop_front();
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};