// https://leetcode-cn.com/problems/top-k-frequent-words/

class Solution {
public:
    static bool cmp(pair<int, string> a, pair<int, string> b) {return a.first==b.first? a.second<b.second:a.first>b.first;}
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> umap;
        for(const auto& word:words) umap[word]++;
        vector<pair<int, string> > counter;
        for(auto iter:umap) counter.push_back(make_pair(iter.second, iter.first));
        sort(counter.begin(), counter.end(), cmp);
        vector<string> res;
        for(int i = 0; i < k; i++) res.push_back(counter[i].second);
        return res;
    }
};