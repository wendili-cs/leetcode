// https://leetcode.com/problems/watering-plants-ii/

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int l = 0, r = plants.size() - 1, lc = capacityA, rc = capacityB, refill = 0;
        vector<bool> filled(plants.size(), false);
        while(l < plants.size() || r >= 0){
            if(l < plants.size()){
                bool met_and_A = (l == r) && (lc > rc);
                if(!filled[l] && ((capacityA >= plants[l] && l != r) || met_and_A)){
                    if(lc < plants[l]){
                        refill++;
                        lc = capacityA;
                    }
                    lc -= plants[l];
                    filled[l] = true;
                }
                l++;
            }
            if(r >= 0){
                if(!filled[r] && capacityB >= plants[r]){
                    if(rc < plants[r]){
                        refill++;
                        rc = capacityB;
                    }
                    rc -= plants[r];
                    filled[r] = true;
                }
                r--;
            }
        }
        return refill;
    }
};