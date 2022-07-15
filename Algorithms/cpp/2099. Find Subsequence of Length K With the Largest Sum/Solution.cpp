// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(make_pair(nums[i], i));
        }
        vector<pair<int, int>> rec;
        for(int i = 0; i < k; i++){
            rec.push_back(make_pair(pq.top().second, pq.top().first));
            pq.pop();
        }
        sort(rec.begin(), rec.end());
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(rec[i].second);
        }
        return res;
    }
};