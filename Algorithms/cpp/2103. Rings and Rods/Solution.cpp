// https://leetcode.com/problems/rings-and-rods/

class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size(), res = 0;
        map<int, set<char>> mp;
        for(int i = 0; i < n/2; i++){
            if(mp[rings[2*i + 1]].size() != 3){
                mp[rings[2*i + 1]].insert(rings[2*i]);
                if(mp[rings[2*i + 1]].size() == 3) res++;
            }
        }
        return res;
    }
};