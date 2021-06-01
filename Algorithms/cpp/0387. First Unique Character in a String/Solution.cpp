// https://leetcode-cn.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, bool> umap;
        for(const auto& c:s){
            if(umap.find(c) == umap.end()) umap[c] = false;
            else umap[c] = true;
        }
        for(int i = 0; i < s.length(); i++){
            if(!umap[s[i]]) return i;
        }
        return -1;
    }
};