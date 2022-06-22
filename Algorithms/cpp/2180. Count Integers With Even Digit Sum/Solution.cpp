// https://leetcode.com/problems/count-integers-with-even-digit-sum/

class Solution {
public:
    int countEven(int num) {
        auto dsum = [](int num) -> int {
            int ret = 0;
            while(num > 0){
                ret += num%10;
                num /= 10;
            }
            return ret;
        };
        int ret = 0;
        for(int i = 2; i <= num; i++){
            if(!(dsum(i)&1)) ret++;
        }
        return ret;
    }
};