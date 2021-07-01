// https://leetcode-cn.com/problems/check-if-it-is-a-good-array/

// 要点：只要最小公倍数是1就可以
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        auto gcd = [](int x, int y) -> int {
            int z = y;
            while(x%y != 0){
                z = x%y;
                x = y;
                y = z;
            }
            return z;
        };
        int t = nums[0];
        for(int num:nums){
            if(gcd(t, num) == 1) return true;
            t = gcd(t, num);
        }
        return false;
    }
};