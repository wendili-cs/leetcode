// https://leetcode.com/problems/neighboring-bitwise-xor/

class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int x = 0;
        for(int num:derived){
            x ^= num;
        }
        return x == 0;
    }
}