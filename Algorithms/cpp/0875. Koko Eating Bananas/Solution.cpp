// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(), piles.end());
        int l = 1, r = 1000000000, mid;
        auto get_time = [&](int k) -> int {
            int ret = 0;
            for(int& p:piles){
                ret += (p/k) + (p%k==0?0:1);
            }
            return ret;
        };
        while(l <= r){
            mid = (l + r)/2;
            if(get_time(mid) <= h){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};