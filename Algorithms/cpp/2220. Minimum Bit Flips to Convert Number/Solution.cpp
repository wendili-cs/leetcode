// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start^goal;
        int x = 1, cnt = 0;
        for(int i = 0; i < 31; i++){
            if(x & diff) cnt++;
            x <<= 1;
        }
        return cnt;
    }
};