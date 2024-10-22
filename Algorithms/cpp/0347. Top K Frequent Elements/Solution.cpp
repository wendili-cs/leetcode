// https://leetcode-cn.com/problems/top-k-frequent-elements/
// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnter;
        for(int &num:nums) {
            cnter[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 小顶堆
        for(auto it:cnter) {
            pq.emplace(it.second, it.first);
            if(pq.size() > k) pq.pop(); // 最多存k个元素，保证push新元素时，其复杂度不大于O(log k)
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};