// https://leetcode.com/problems/minimum-moves-to-reach-target-score/

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int curD = 0, res = 0;
        while(target != 1){
            if(!(target&1) && curD < maxDoubles){
                target /= 2;
                curD++;
            }
            else if(curD == maxDoubles){
                res += target - 1;
                break;
            }
            else{
                target--;
            }
            res++;
        }
        return res;
    }
};