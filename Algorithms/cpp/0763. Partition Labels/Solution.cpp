// https://leetcode-cn.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.length(), start = 0, end = 0;
        if(len == 1) return {1};
        vector<int> res;
        unordered_map<char, int> umap;
        for(int i = 0; i < len; i++) umap[s[i]] = i;
        for(int i = 0; i < len; i++){
            end = max(end, umap[s[i]]); // 找到目前最远的index
            if(i == end){
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};