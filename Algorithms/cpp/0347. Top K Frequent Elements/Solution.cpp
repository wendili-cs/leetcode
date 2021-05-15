// https://leetcode-cn.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(const auto& num:nums){
            umap[num]++;
        }
        priority_queue<pair<int, int>> max_heap;
        for(auto iter = umap.begin(); iter != umap.end(); iter++){
            max_heap.emplace(iter->second, iter->first);
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return res;
    }
};