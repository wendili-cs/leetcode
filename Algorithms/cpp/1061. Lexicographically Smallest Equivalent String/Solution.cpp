// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> dset(26);
        for(int i = 0; i < 26; i++) dset[i] = i;
        function<int(int)> find;
        find = [&](int x) -> int {
            if(dset[x] != x){
                dset[x] = find(dset[x]);
            }
            return dset[x];
        };
        for(int i = 0; i < s1.length(); i++){
            // find their current group
            int x = find(s1[i] - 'a'), y = find(s2[i] - 'a');
            // merge larger one to smaller one
            dset[find(max(x, y))] = find(min(x, y));
        }
        for(int i = 0; i < baseStr.length(); i++){
            baseStr[i] = find(baseStr[i] - 'a') + 'a';
        }
        return baseStr;
    }
};