// https://leetcode-cn.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > q;
        for(int i = 0; i < k; i++){ // 填充第一个滑动窗口
            q.emplace(nums[i], i);
        }
        res.push_back(q.top().first);
        for(int i = k; i < len; i++){
            q.emplace(nums[i], i);
            while(q.top().second <= i - k){ // 这里是只需要剔除最大的、不在滑动窗口范围内的，q的元素不需要是当前滑动窗口的元素
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
};