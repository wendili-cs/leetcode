// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/

// 思想：用字典当记词器
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size(), num = words.size();
        vector<int> res;
        unordered_map<string, int> umap, amap;
        for(auto& word:words) umap[word]++;
        auto is_match = [&](string S) -> bool {
            amap = umap;
            for(int i = 0; i < num; i++){
                string temp = S.substr(i*len, len);
                if(amap[temp] <= 0) return false;
                else amap[temp]--;
            }
            return true;
        };
        for(int i = 0; i + len*num <= s.length(); i++){
            if(is_match(s.substr(i))) res.push_back(i);
        }
        return res;
    }
};