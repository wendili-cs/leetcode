// https://leetcode.com/problems/knight-dialer/

class Solution {
public:
    int knightDialer(int n) {
        if(n == 1) return 10; // only this case uses 5
        // 1, 3, 7, 9 are the same; 2, 8 are the same; 4, 6 are the same, and 0
        long corner = 4, two_eight = 2, four_six = 2, zero = 1, mod = 1000000007;
        for(int i = 0; i < n - 1; i++){
            long new_corner = 2*two_eight + 2*four_six;
            long new_two_eight = corner;
            long new_four_six = corner + 2*zero;
            long new_zero = four_six;
            
            corner = new_corner%mod;
            two_eight = new_two_eight%mod;
            four_six = new_four_six%mod;
            zero = new_zero%mod;
        }
        return (corner + two_eight + four_six + zero)%mod;
    }
};