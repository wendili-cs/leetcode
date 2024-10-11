// https://leetcode-cn.com/problems/top-k-frequent-elements/
// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnter;
        for(int &num:nums) {
            cnter[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it:cnter) {
            pq.emplace(it.second, it.first);
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};