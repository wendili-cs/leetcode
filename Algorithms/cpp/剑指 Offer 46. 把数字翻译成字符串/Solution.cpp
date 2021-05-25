// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/

class Solution {
public:
    int translateNum(int num) {
        int res = 0;
        function<void(int)> recur;
        recur = [&](int a) -> void {
            if(a == 0){
                res += 1;
                return;
            }
            recur(a/10);
            if(a > 9 && 9 < a % 100 && a % 100 < 26){
                recur(a/100);
            }
        };
        recur(num);
        return res;
    }
};