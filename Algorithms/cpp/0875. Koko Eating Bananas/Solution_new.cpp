// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int mid = l + (r - l)/2;
            int days = 0;
            for(int pile:piles){
                if(pile % mid != 0) days++; // eat remaining part
                days += pile/mid;
            }
            if(days > h){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};