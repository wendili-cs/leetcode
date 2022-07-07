// https://leetcode.com/problems/destroying-asteroids/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long lmass = mass;
        for(int& m:asteroids){
            if(lmass < m) return false;
            lmass += m;
        }
        return true;
    }
};