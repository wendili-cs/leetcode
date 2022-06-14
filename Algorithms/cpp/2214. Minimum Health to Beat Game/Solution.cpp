// https://leetcode.com/problems/minimum-health-to-beat-game/

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long res = 1, max_dam = 0;
        for(int i = 0; i < damage.size(); i++){
            max_dam = (max_dam >= damage[i])?max_dam:damage[i];
            res += damage[i];
        }
        res -= (max_dam >= armor)?armor:max_dam;
        return res;
    }
};