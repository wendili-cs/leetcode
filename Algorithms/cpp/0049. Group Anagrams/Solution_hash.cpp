// https://leetcode-cn.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > umap;
        for(const auto& str:strs){
            string key = str;
            sort(key.begin(), key.end());
            umap[key].emplace_back(str);
        }
        vector<vector<string> > res;
        for(auto iter = umap.begin(); iter != umap.end(); iter++){
            res.push_back(iter->second);
        }
        return res;
    }
};