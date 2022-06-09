// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        auto check_c = [&](int c) -> bool {
            long cur = 0;
            for(int& candy:candies){
                cur += candy/c;
            }
            return cur >= k;
        };
        int l = 0, r = 10000000, mid;
        while(l < r){
            mid = (r + l + 1)/2;
            if(check_c(mid)) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};