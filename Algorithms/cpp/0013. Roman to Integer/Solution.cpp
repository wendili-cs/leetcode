// https://leetcode-cn.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;

        for(int i = 0; i < s.length(); i++){
            if(umap[s[i]] >= umap[s[i + 1]]) res += umap[s[i]];
            else res -= umap[s[i]];
        }
        return res;
    }
};