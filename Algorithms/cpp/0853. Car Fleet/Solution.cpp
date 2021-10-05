// https://leetcode.com/problems/car-fleet/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;
        for(int i = 0; i < position.size(); i++){
            ps.push_back(make_pair(position[i], speed[i]));
        }
        sort(ps.begin(), ps.end());
        reverse(ps.begin(), ps.end());
        double lm = 0;
        int res = 0;
        for(auto aps:ps){
            double is = ((double)target - aps.first)/aps.second;
            if(is > lm){
                lm = is;
                res++;
            }
        }
        return res;
    }
};