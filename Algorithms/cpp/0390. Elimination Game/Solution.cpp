// https://leetcode.com/problems/elimination-game/

class Solution {
public:
    int lastRemaining(int n) {
        int remain = n, step = 1, head = 1;
        bool left = true;
        while(remain > 1){
            if(left || remain%2 == 1){
                head += step; // the first one is removed
            }
            remain /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};