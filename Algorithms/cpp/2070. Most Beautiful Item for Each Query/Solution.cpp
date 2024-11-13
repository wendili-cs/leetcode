// https://leetcode.com/problems/most-beautiful-item-for-each-query/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        map<int, int> mp;
        int cur_max_price = 0;
        for(auto &p:items){
            mp[-p[0]] = max(cur_max_price, p[1]);
            cur_max_price = mp[-p[0]];
        }
        vector<int> res;
        for(int q:queries){
            auto it = mp.lower_bound(-q);
            res.push_back(it->second);
        }
        return res;
    }
};