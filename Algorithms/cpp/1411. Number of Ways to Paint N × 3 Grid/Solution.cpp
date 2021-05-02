// https://leetcode-cn.com/problems/number-of-ways-to-paint-n-3-grid/

class Solution {
public:
    int numOfWays(int n) {
        const int mod = 1000000007;
        int res = 0;
        long long pre_ABA = 6, pre_ABC = 6;
        long long ABA = pre_ABA, ABC = pre_ABC;
        for(int i = 1; i < n; i++){
            ABA = (pre_ABA * 3 + pre_ABC * 2) % mod;
            ABC = ((pre_ABA + pre_ABC) * 2) % mod;
            pre_ABA = ABA;
            pre_ABC = ABC;
        }
        return (ABA + ABC) % mod;
    }
};